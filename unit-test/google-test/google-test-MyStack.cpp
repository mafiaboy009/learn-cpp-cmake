#include "google-test-MyStack.hpp"
#include <stdexcept>

/*
 * code duplication is evil
 * global variable too are evil
 *
 * test fixture 
 * -- is a class containing 
 */
class MyStackTest: public ::testing::Test {
    protected: // Either public or protected. Cannot be private
        MyStack st;

        MyStackTest(){
            st.push(7);
        }

        virtual void SetUp(){
            st.push(9);
        }

        virtual void TearDown(){
        }

        ~MyStackTest(){
            cout << "Stack destructed." << newLine;
        }
};

// A test with test Fixture
//TEST_F( MyStackTest, DISABLED_testPop){ // first argument must be test fixture class name
TEST_F( MyStackTest, testPop){ // first argument must be test fixture class name
    int val = st.top();
    EXPECT_EQ(9, val);
}


// ( testcase name, test name )
TEST( StackTest, testPop_pt){
    MyStack st;
    st.push(9);
    EXPECT_EQ(9, st.top());
}

TEST( StackTest, testPop_nt){
    MyStack st;
    try{
        st.pop();
        FAIL() << "Expected std::runtime_error";
    }
    catch( std::runtime_error& e){
        EXPECT_STREQ( "stack empty!", e.what());
    }
}

TEST( StackTest, testPop_nt1){
    MyStack st;
    EXPECT_THROW( st.pop(), std::runtime_error );
    EXPECT_ANY_THROW( st.pop() );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
