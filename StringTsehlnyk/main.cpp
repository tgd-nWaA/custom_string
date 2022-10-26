#include "String.h"
#include "test.h"

int main()
{
    {
        String str("");
        ASSERT_EQ(str, "");
        str = "hello";
        ASSERT_EQ(str, "hello");
        ASSERT_EQ(str.length(), 5);
        cout << str << endl;
    }
    {
        String str("abcd");
        string std_string("abdc");
        ASSERT(str < std_string);
        ASSERT(str < "abcda");
        ASSERT_NOT(str < "abc");
        ASSERT_NOT(str < "abcd");
    }
    {
        String str = "ab";
        ASSERT_EQ(str * 4, "abababab");
        ASSERT_EQ(str * 4, 4 * str);
        ASSERT_EQ(str.length(), 2);
        str *= 3;
        ASSERT_EQ(str.length(), 6);
    }
    {
        String str = "abc";
        ASSERT_EQ(str.length(), 3);
        ASSERT_EQ(str + "de", "abcde");
        ASSERT_EQ("de" + str, "deabc");
        str += "de";
        ASSERT_EQ(str, "abcde");
        ASSERT_EQ(str.length(), 5);
    }
    {
        String str = "abc";
        ASSERT_EQ(str[0], 'a');
        ASSERT_EQ(str[2], 'c');
        str[1] = 'k';
        ASSERT_EQ(str[1], 'k');
        ASSERT_EQ(str, "akc");
        ASSERT_THROW(str[5]);
    }
}