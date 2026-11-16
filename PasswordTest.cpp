/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, website_password_www)
{
	Password my_password;
	int actual = my_password.count_leading_characters("WWW.");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, website_password_https)
{
	Password my_password;
	int actual = my_password.count_leading_characters("https");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, has_mixed_case_upper)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ABCIENSGHKSHFD");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, has_mixed_case_lower)
{
	Password my_password;
	int actual = my_password.count_leading_characters("adkgjhsdjkgba");
	ASSERT_EQ(true, actual);
}
TEST(PasswordTest, has_mixed_case_mixed)
{
	Password my_password;
	int actual = my_password.count_leading_characters("sdjhOKLHSDOGHjlmshdngoj");
	ASSERT_EQ(true, actual);
}