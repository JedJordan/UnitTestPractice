/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public::testing::Test
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
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, case_sensitive_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ZZZzzz");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, leading_characters_only)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Zoom");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, special_character_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("****hehe****");
	ASSERT_EQ(4,actual);
}

TEST(PasswordTest,space_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("   ");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, number_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("1123");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, mixed_case_password)
{
    Password my_password;
        int actual = my_password.has_mixed_case("aaaBBB");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, mixed_case_password2)
{
    Password my_password;
    int actual = my_password.has_mixed_case("BBBaaa");
    ASSERT_EQ(1,actual);
}

TEST(PasswordTest, mixed_case_password3)
{
    Password my_password;
    int actual = my_password.has_mixed_case("aBaBaB");
    ASSERT_EQ(1,actual);
}
TEST(PasswordTest, empty_password)
{
    Password my_password;
    int actual = my_password.has_mixed_case("");
    ASSERT_EQ(0,actual);
}
TEST(PasswordTest, spaces_before_mixed_password)
{
    Password my_password;
    int actual = my_password.has_mixed_case("  Za");
    ASSERT_EQ(1,actual);
}
TEST(PasswordTest, numbers_ascii_password4)
{
    Password my_password;
    int actual = my_password.has_mixed_case("!@#b$%^&*(Z)");
    ASSERT_EQ(1,actual);
}
TEST(PasswordTest, default_password)
{
    Password my_password;
    int actual = my_password.authenticate("ChicoCA-95929");
    ASSERT_EQ(1,actual);
}
TEST(PasswordTest, set_and_default_password)
{
    Password my_password;
    my_password.set("ChicoRocks");
    int actual = my_password.authenticate("ChicoCA-95929");
    ASSERT_EQ(0,actual);
}
TEST(PasswordTest, long_password)
{
    Password my_password;
    my_password.set("    Chico");
    int actual = my_password.authenticate("    Chico");
    ASSERT_EQ(0,actual);
}
TEST(PasswordTest, non_mixed_password)
{
    Password my_password;
    my_password.set("123AZ321");
    int actual = my_password.authenticate("123AZ321");
    ASSERT_EQ(0,actual);
}