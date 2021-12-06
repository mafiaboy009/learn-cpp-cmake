Expectation -- Non Fatal Assertion
EXPECT_EQ
EXPECT_NE
EXPECT_GT
EXPECT_LE
EXPECT_TRUE

Assertion -- Fatal Assertion
ASSERT_EQ
ASSERT_NE
ASSERT_GT
ASSERT_LE
ASSERT_TRUE

String Specific
EXPECT_STREQ
EXPECT_STRCASEEQ //ignore case when comparing strings

Floating point comparison
EXPECT_FLOAT_EQ
EXPECT_DOUBLE_EQ
EXPECT_NEAR(expected, actual, tolerance)

Note: Corresponding assert are also available

**DEATH Test**
I. EXPECT_DEATH( fun, "message.*");
Reason for death
--1. Program exited with nonzero code
--2. Program was killed by a signal
Convention
-- testcase name should end with "DeathTest"
-- DeathTests usually need to be run before other test

II. EXPECT_EXIT( fun, ::testing::ExitedWithCode(1), "message.*");

III. EXPECT_EXIT( fun, ::testing::ExitedWithCode(1), ""); // if we dont care about message

IV. EXPECT_EXIT( fun, ::testing::KilledBySignal(SIGKILL), ".*"); // not supported on windows
Note: Exceptions are not considered as Death; Exceptions can be caught and processed

EXPECT_THROW
EXPECT_ANY_THROW
EXPECT_NO_THROW

FAIL() << " a message "

This program contains tests written using Google Test. You can use the
following command line flags to control its behavior:

Test Selection:
  --gtest_list_tests
      List the names of all tests instead of running them. The name of
      TEST(Foo, Bar) is "Foo.Bar".
  --gtest_filter=POSTIVE_PATTERNS[-NEGATIVE_PATTERNS]
      Run only the tests whose name matches one of the positive patterns but
      none of the negative patterns. '?' matches any single character; '*'
      matches any substring; ':' separates two patterns.
  --gtest_also_run_disabled_tests
      Run all disabled tests too.

Test Execution:
  --gtest_repeat=[COUNT]
      Run the tests repeatedly; use a negative count to repeat forever.
  --gtest_shuffle
      Randomize tests' orders on every iteration.
  --gtest_random_seed=[NUMBER]
      Random number seed to use for shuffling test orders (between 1 and
      99999, or 0 to use a seed based on the current time).

Test Output:
  --gtest_color=(yes|no|auto)
      Enable/disable colored output. The default is auto.
  --gtest_print_time=0
      Don't print the elapsed time of each test.
  --gtest_output=(json|xml)[:DIRECTORY_PATH/|:FILE_PATH]
      Generate a JSON or XML report in the given directory or with the given
      file name. FILE_PATH defaults to test_detail.xml.
  --gtest_stream_result_to=HOST:PORT
      Stream test results to the given server.

Assertion Behavior:
  --gtest_death_test_style=(fast|threadsafe)
      Set the default death test style.
  --gtest_break_on_failure
      Turn assertion failures into debugger break-points.
  --gtest_throw_on_failure
      Turn assertion failures into C++ exceptions for use by an external
      test framework.
  --gtest_catch_exceptions=0
      Do not report exceptions as test failures. Instead, allow them
      to crash the program or throw a pop-up (on Windows).

Except for --gtest_list_tests, you can alternatively set the corresponding
environment variable of a flag (all letters in upper-case). For example, to
disable colored text output, you can either specify --gtest_color=no or set
the GTEST_COLOR environment variable to no.

For more information, please read the Google Test documentation at
https://github.com/google/googletest/. If you find a bug in Google Test
(not one in your own code or tests), please report it to
<googletestframework@googlegroups.com>.
