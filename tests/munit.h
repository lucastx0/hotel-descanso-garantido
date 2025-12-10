/* µnit Testing Framework
 * Copyright (c) 2013-2017 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 */

#ifndef MUNIT_H
#define MUNIT_H

#include <stdarg.h>
#include <stdlib.h>

#define MUNIT_VERSION(major, minor, revision) \
  (((major) << 16) | ((minor) << 8) | (revision))

#define MUNIT_CURRENT_VERSION MUNIT_VERSION(0, 4, 1)

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum {
  MUNIT_LOG_DEBUG,
  MUNIT_LOG_INFO,
  MUNIT_LOG_WARNING,
  MUNIT_LOG_ERROR
} MunitLogLevel;

typedef enum {
  MUNIT_OK,
  MUNIT_FAIL,
  MUNIT_SKIP,
  MUNIT_ERROR
} MunitResult;

typedef struct {
  char* name;
  void* data;
} MunitParameterEnum;

typedef struct {
  char* name;
  char** values;
} MunitParameter;

typedef MunitResult (* MunitTestFunc)(const MunitParameter params[], void* user_data_or_fixture);
typedef void* (* MunitTestSetup)(const MunitParameter params[], void* user_data);
typedef void (* MunitTestTearDown)(void* fixture);

typedef struct {
  char* name;
  MunitTestFunc test;
  MunitTestSetup setup;
  MunitTestTearDown tear_down;
  int options;
  MunitParameter* parameters;
} MunitTest;

typedef enum {
  MUNIT_SUITE_OPTION_NONE = 0
} MunitSuiteOptions;

typedef struct MunitSuite_ MunitSuite;

struct MunitSuite_ {
  char* prefix;
  MunitTest* tests;
  MunitSuite* suites;
  unsigned int iterations;
  MunitSuiteOptions options;
};

int munit_run_suite(const MunitSuite* suite);

void munit_logf_ex(MunitLogLevel level, const char* filename, int line, const char* format, ...);

#define munit_logf(level, format, ...) \
  munit_logf_ex(level, __FILE__, __LINE__, format, __VA_ARGS__)

void munit_errorf_ex(const char* filename, int line, const char* format, ...);

#define munit_errorf(format, ...) \
  munit_errorf_ex(__FILE__, __LINE__, format, __VA_ARGS__)

#define munit_assert(expr) \
  do { \
    if (!(expr)) { \
      munit_errorf("assertion failed: %s", #expr); \
    } \
  } while (0)

#define munit_assert_true(expr) \
  do { \
    if (!(expr)) { \
      munit_errorf("assertion failed: %s is not true", #expr); \
    } \
  } while (0)

#define munit_assert_false(expr) \
  do { \
    if ((expr)) { \
      munit_errorf("assertion failed: %s is not false", #expr); \
    } \
  } while (0)

#define munit_assert_int(a, op, b) \
  do { \
    int munit_tmp_a_ = (a); \
    int munit_tmp_b_ = (b); \
    if (!(munit_tmp_a_ op munit_tmp_b_)) { \
      munit_errorf("assertion failed: %s %s %s (%d %s %d)", \
        #a, #op, #b, munit_tmp_a_, #op, munit_tmp_b_); \
    } \
  } while (0)

#define munit_assert_string_equal(a, b) \
  do { \
    const char* munit_tmp_a_ = a; \
    const char* munit_tmp_b_ = b; \
    if (strcmp(munit_tmp_a_, munit_tmp_b_) != 0) { \
      munit_errorf("assertion failed: strings not equal\n  expected: %s\n  got: %s", \
        munit_tmp_b_, munit_tmp_a_); \
    } \
  } while (0)

#define munit_assert_float(a, op, b) \
  do { \
    float munit_tmp_a_ = (a); \
    float munit_tmp_b_ = (b); \
    if (!(munit_tmp_a_ op munit_tmp_b_)) { \
      munit_errorf("assertion failed: %s %s %s (%.2f %s %.2f)", \
        #a, #op, #b, munit_tmp_a_, #op, munit_tmp_b_); \
    } \
  } while (0)

#define munit_assert_null(ptr) \
  do { \
    if ((ptr) != NULL) { \
      munit_errorf("assertion failed: %s is not NULL", #ptr); \
    } \
  } while (0)

#define munit_assert_not_null(ptr) \
  do { \
    if ((ptr) == NULL) { \
      munit_errorf("assertion failed: %s is NULL", #ptr); \
    } \
  } while (0)

#if defined(__cplusplus)
}
#endif

#endif /* !defined(MUNIT_H) */

#ifdef MUNIT_ENABLE_ASSERT_ALIASES
#define assert_true(expr) munit_assert_true(expr)
#define assert_false(expr) munit_assert_false(expr)
#define assert_int(a, op, b) munit_assert_int(a, op, b)
#define assert_string_equal(a, b) munit_assert_string_equal(a, b)
#define assert_null(ptr) munit_assert_null(ptr)
#define assert_not_null(ptr) munit_assert_not_null(ptr)
#endif

/* Implementation */
#ifdef MUNIT_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <time.h>

static int munit_error_count = 0;

void munit_logf_ex(MunitLogLevel level, const char* filename, int line, const char* format, ...) {
  const char* level_str;
  
  switch (level) {
    case MUNIT_LOG_DEBUG: level_str = "DEBUG"; break;
    case MUNIT_LOG_INFO: level_str = "INFO"; break;
    case MUNIT_LOG_WARNING: level_str = "WARNING"; break;
    case MUNIT_LOG_ERROR: level_str = "ERROR"; break;
    default: level_str = "UNKNOWN"; break;
  }
  
  fprintf(stderr, "[%s] %s:%d: ", level_str, filename, line);
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  fprintf(stderr, "\n");
}

void munit_errorf_ex(const char* filename, int line, const char* format, ...) {
  fprintf(stderr, "\n[FAIL] %s:%d: ", filename, line);
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  fprintf(stderr, "\n\n");
  munit_error_count++;
  exit(MUNIT_FAIL);
}

int munit_run_suite(const MunitSuite* suite) {
  int total = 0;
  int passed = 0;
  int failed = 0;
  int skipped = 0;
  
  printf("\n");
  printf("================================================================================\n");
  printf("  Running test suite: %s\n", suite->prefix ? suite->prefix : "Tests");
  printf("================================================================================\n\n");
  
  MunitTest* test = suite->tests;
  while (test && test->name) {
    total++;
    printf("[ RUN      ] %s\n", test->name);
    
    void* fixture = NULL;
    if (test->setup) {
      fixture = test->setup(NULL, NULL);
    }
    
    munit_error_count = 0;
    MunitResult result = test->test(NULL, fixture);
    
    if (test->tear_down) {
      test->tear_down(fixture);
    }
    
    if (result == MUNIT_OK && munit_error_count == 0) {
      printf("[       OK ] %s\n\n", test->name);
      passed++;
    } else if (result == MUNIT_SKIP) {
      printf("[     SKIP ] %s\n\n", test->name);
      skipped++;
    } else {
      printf("[   FAILED ] %s\n\n", test->name);
      failed++;
    }
    
    test++;
  }
  
  printf("================================================================================\n");
  printf("  Test Results:\n");
  printf("  Total:   %d\n", total);
  printf("  Passed:  %d\n", passed);
  printf("  Failed:  %d\n", failed);
  printf("  Skipped: %d\n", skipped);
  printf("================================================================================\n\n");
  
  return (failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

#endif /* MUNIT_IMPLEMENTATION */
