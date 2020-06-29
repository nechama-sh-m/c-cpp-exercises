//
// Created by student on 09/06/2020.
//

#include "test.h"
/*TEST(TestBasic,TestConstractor){
    Price p1(12,4);
    ASSERT_EQ(double (p1),12.04);
    Price p2(-12,4);
    ASSERT_EQ(double (p2),-12.04);
}
TEST(testOperator,TestPlus){
    Price p1(5,25);
    Price p2(-6);
    ASSERT_EQ(-0.75,double(p1+p2));
    Price p3(12,4);
    Price p4(-20,4);
    ASSERT_EQ(double(p3+p4),-8);
}

TEST(testOperator,TestMin) {
    Price p1(12, 4);
    Price p2(12, 4);
    ASSERT_EQ(0, double (p1 - p2));
    Price p3(12, 4);
    Price p4(-20, 4);
    ASSERT_EQ(32.08, double(p3 - p4));
}*/
/*TEST(testOperator,TestMul) {
    Price p1(2, 4);
    Price p2(0);
    ASSERT_EQ(0, (p1 * p2).get_price_in_cent());
    Price p3(1);
    Price p4(-20, 4);
    ASSERT_EQ(-200400, (p3 * p4).get_price_in_cent());
}
TEST(testOperator,TestDev) {
    Price p1(2, 4);
    Price p2(2);
    ASSERT_EQ(1, (p1 / p2).get_price_in_cent());
    Price p3(-2);
    Price p4(0, -50);
    ASSERT_EQ(4, (p3 / p4).get_price_in_cent());
}
TEST(testOperator,TestMod) {
    Price p1(5, 30);
    Price p2(2);
    ASSERT_EQ( (p1 % p2).get_price_in_cent(),130);
    Price p3(-2,3);
    Price p4(2);
    ASSERT_EQ(-3, (p3 % p4).get_price_in_cent());
}*/

/*TEST(testOperator,TestPlusEq){
    Price p1(12,4);
    Price p2(12,4);
    p1+=p2;
    ASSERT_EQ(double (p1),24.08);
    Price p3(12,4);
    Price p4(-20,4);
    p3+=p4;
    ASSERT_EQ(double (p3),-8);
}

TEST(testOperator,TestMinEq){
    Price p1(12,4);
    Price p2(13,4);
    p1-=p2;
    ASSERT_EQ(double (p1),-1);
    Price p3(12,4);
    Price p4(-20,4);
    p3-=p4;
    ASSERT_EQ(double(p3),32.08);
}*/
/*TEST(testOperator,TestMulEq){
    Price p1(12,4);
    Price p2(0);
    p1*=p2;
    ASSERT_EQ(p1.get_price_in_cent(),0);
    Price p3(2);
    Price p4(0,-4);
    p3*=p4;
    ASSERT_EQ(p3.get_price_in_cent(),-800);
}
TEST(testOperator,TestDevEq){
    Price p1(12,4);
    Price p2(4);
    p1/=p2;
    ASSERT_EQ(p1.get_price_in_cent(),3);
    Price p3(2);
    Price p4(0,-4);
    p3/=p4;
    ASSERT_EQ(p3.get_price_in_cent(),-50);
}
TEST(testOperator,TestModEq){
    Price p1(2);
    Price p2(0,5);
    p1%=p2;
    ASSERT_EQ(p1.get_price_in_cent(),0);
    Price p3(2,2);
    Price p4(2);
    p3%=p4;
    ASSERT_EQ(p3.get_price_in_cent(),2);
}*/

TEST(TestCtor, CreatePrice)
{
    Price<1> p1(5,25);
    ASSERT_FLOAT_EQ(double(p1), 5.2);
    //Price<1,char> p2(5,-25);
    //ASSERT_FLOAT_EQ(double(p2), -5.2);
    Price<1,short> p3;
    ASSERT_FLOAT_EQ(double(p3), 0);
    Price<2,long> p4(999999999,99);
    ASSERT_EQ(p4.getDollar(), 999999999);
    ASSERT_EQ(p4.getCent(), 99);
}

TEST(TestOperator, TestPlusOp)
{
    Price<3,int> p1(5,2524);
    std::cout<<p1<<std::endl;
    Price<3,int> p2(2,5);
    std::cout<<p2<<std::endl;
    Price<3,int> p3(-1);

    Price<3,int> p4=p3+p1;
    ASSERT_DOUBLE_EQ(double(p1+p2), 7.257);
    ASSERT_DOUBLE_EQ(p1+5, 10.252);
    ASSERT_DOUBLE_EQ(double(p4), 4.252);
}

TEST(TestOperator, TestMinusOp)
{
    Price<3,int> p1(5,25852);
    Price<3,int> p2(2,50);
    ASSERT_DOUBLE_EQ(double(p1-p2), 3.208);
    ASSERT_DOUBLE_EQ(double(p2-p1), -3.208);
    ASSERT_DOUBLE_EQ(p1-5, 0.258);

}

/*TEST(ArithmeticOperatorTest, MultiplicationOp)
{
    Price p1(5,25);
    Price p2(2);
    ASSERT_EQ((p1*p2).get_price_in_cents(), 105000);
    ASSERT_EQ((p2*5).get_price_in_cents(), 100000);
    ASSERT_EQ((p2*-5).get_price_in_cents(), -100000);
}

TEST(ArithmeticOperatorTest, DivideOp)
{
    Price p1(6,25);
    Price p2(2,50);
    Price p3(-2,50);
    ASSERT_EQ((p1/p2).get_price_in_cents(), 2);
    ASSERT_EQ((p1/3).get_price_in_cents(), 2);
    ASSERT_EQ((p2/p3).get_price_in_cents(), -1);
}

TEST(ArithmeticOperatorTest, ModuloOp)
{
    Price p1(5,30);
    Price p2(2);
    ASSERT_EQ((p1%p2).get_price_in_cents(), 130);
    ASSERT_EQ((p2%5).get_price_in_cents(), 200);
    ASSERT_EQ((p2%1).get_price_in_cents(), 0);
}*/


TEST(TestOperator, TestPlusEqOp)
{
    Price<4,int> p1(5,25);
    Price<4,int> p2(2,5);
    Price<4,int> p3(-2,5);
    p1+=p2;
    p2+=2;
    p3+=1;
    ASSERT_DOUBLE_EQ(double(p1), 7.003);
    ASSERT_DOUBLE_EQ(double(p2), 4.0005);
    ASSERT_DOUBLE_EQ(double(p3), -1.0005);
}

TEST(TestOperator, TestMinusEqOp) {
    Price<1,int> p1(5, 25);
    Price<1,int> p2(2, 5);
    p1 -= p2;
    p2 -= 3;
    ASSERT_DOUBLE_EQ(double(p1), 2.7);
    ASSERT_EQ(double(p2), -0.5);
}

/*TEST(ArithmeticOperatorTest, MultEqOp)
{
    Price p1(5,25);
    Price p2(2,5);
    Price p3(-2,5);
    p1*=p2;
    p2*=1;
    p3*=1;
    ASSERT_EQ(p1.get_price_in_cents(), 107625);
    ASSERT_EQ(p2.get_price_in_cents(), 20500);
    ASSERT_EQ(p3.get_price_in_cents(), -20500);
}*/

TEST(TestOperator, TestUnary)
{
    Price<3,int> p1(5,25);
    ASSERT_DOUBLE_EQ(double(-p1), -5.025);
}

TEST(TestOperator, TestPreIncreaseOp)
{
    Price<2,int> p1(5,25);
    Price<2,int> p2(-1);
    Price<2,int> p3(0,-25);
    ++p1;
    ++p2;
    ++p3;
    ASSERT_DOUBLE_EQ(double(p1), 6.25);
    ASSERT_DOUBLE_EQ(double(p2), 0);
    ASSERT_DOUBLE_EQ(double(p3), 0.75);
}

TEST(TestOperator, TestPreDecreaseOp)
{
    Price<1,int> p1(5,25);
    Price<1,int> p2(0,25);
    --p1;
    --p2;
    ASSERT_DOUBLE_EQ(double(p1), 4.2);
    ASSERT_DOUBLE_EQ(double(p2), -0.8);
}

TEST(TestOperator, TestPostIncreaseOp)
{
    Price<2,int> p1(5,25);
    Price<2,int> p2(-1);
    Price<2,int> p3(0,-25);
    p1++;
    p2++;
    p3++;
    ASSERT_DOUBLE_EQ(double(p1), 6.25);
    ASSERT_DOUBLE_EQ(double(p2), 0);
    ASSERT_DOUBLE_EQ(double(p3), 0.75);
}

TEST(TestOperator, TestPostDecreaseOp)
{
    Price<3,int> p1(5,25);
    Price<3,int> p2(0,25);
    p1--;
    p2--;
    ASSERT_DOUBLE_EQ(double(p1), 4.025);
    ASSERT_DOUBLE_EQ(double(p2), -0.975);
}

TEST(TestComparisonOperator, TestEqual)
{
    Price<2,int> p1(5,25);
    Price<2,int> p2(5,25);
    Price<2,int> p3(2,5);
    ASSERT_TRUE(p1==p2);
    ASSERT_FALSE(p1==p3);
}


TEST(TestComparisonOperator, TestNotEqual)
{
    Price<3,int> p1(5,25);
    Price<3,int> p2(5,25);
    Price<3,int> p3(2,5);
    ASSERT_TRUE(p1!=p3);
    ASSERT_FALSE(p1!=p2);
}


TEST(TestComparisonOperator, TestSmaller)
{
    Price<3,int> p1(5,25);
    Price<3,int> p2(2,5);
    ASSERT_FALSE(p1<p2);
    ASSERT_TRUE(p2<p1);
}

TEST(TestComparisonOperator, TestLarger)
{
    Price<1,int> p1(5,25);
    Price<1,int> p2(2,5);
    ASSERT_TRUE(p1>p2);
    ASSERT_FALSE(p2>p1);
}

TEST(TestComparisonOperator, TestSmallerEqual)
{
    Price<2,int> p1(5,25);
    Price<2,int> p2(2,5);
    Price<2,int> p3(2,5);
    ASSERT_FALSE(p1<=p2);
    ASSERT_TRUE(p2<=p3);
}

TEST(TestComparisonOperator, TestLargerEqual)
{
    Price<1,int> p1(5,25);
    Price<1,int> p2(2,5);
    Price<1,int> p3(2,5);
    ASSERT_FALSE(p2>=p1);
    ASSERT_TRUE(p2>=p3);
}

TEST(TestBasic,TestAssignmentOp)
{
    Price<1,int> p1;
    p1=7;
    Price<1,int> p2;
    p2=-7;
    ASSERT_DOUBLE_EQ(double(p1),7.0);
    ASSERT_DOUBLE_EQ(double(p2),-7.0);
}

TEST(TestBasic, TestPrint)
{
    Price<3,int> p1(5,25);
    Price<3,int> p2(1,-30);
    ASSERT_TRUE(std::cout<<p1);
    ASSERT_TRUE(std::cout<<p2);
}

TEST(TestBasic, TestCastToDouble)
{
    Price<2,int> p1(5,25);
    ASSERT_DOUBLE_EQ(double(p1), 5.25);
}