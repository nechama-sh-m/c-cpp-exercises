//
// Created by student on 07/06/2020.
//

#include "test.h"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

}

TEST(DnaBasicTests,TestConstractor)
{
    const char * c_good="TCGA";
    const char * c_bad ="BBB";
    DnaSeq d1(c_good);
    ASSERT_EQ("TCGA",d1.get_seq());
    ASSERT_THROW(DnaSeq d2(c_bad),InvalidDna);
    std::string s_good="TATC";
    std::string s_bad ="BBB";
    DnaSeq d3(s_good);
    ASSERT_EQ("TATC",d3.get_seq());
    ASSERT_THROW(DnaSeq d2(c_bad),InvalidDna);
    DnaSeq d4(d3);
    ASSERT_EQ(d4.get_seq(),d3.get_seq());
    DnaSeq d5=d1;
    ASSERT_EQ(d5.get_seq(),d1.get_seq());
 }


TEST(TestOperator,TestAssignmantOperator)
{
    DnaSeq d1("AAA");
    DnaSeq d2("A");
    d1=d2;
    ASSERT_EQ(d1.get_seq(),d2.get_seq());

}
TEST(TestOperator,TestComparisonOperator)
{
    DnaSeq d1("AAA");
    DnaSeq d2("A");
    DnaSeq d3("A");
    ASSERT_TRUE(d2==d2);
    ASSERT_TRUE(d1!=d3);
}

TEST(TestOperator,TestArryOperator)
{
    DnaSeq d1("ACA");
    ASSERT_EQ('C', char(d1[1]));
    d1[0]='T';
    ASSERT_EQ(char(d1[0]), 'T');

}
TEST(TestFun,TestSlice)
{
    DnaSeq d1("ATCTCAAG");
    ASSERT_EQ("CTC", d1.slice(1,5).get_seq());
}
TEST(TestFun,TestPair)
{
    DnaSeq d1("GCAC");
    ASSERT_EQ("GTGC", d1.pairing().get_seq());
}
TEST(TestFun,TestFind)
{
    DnaSeq d1("GCAC");
    ASSERT_EQ(1, d1.findIndexSub("CA"));
}
TEST(TestFun,TestCount)
{
    DnaSeq d1("GCACGCAATCA");
    ASSERT_EQ(3, d1.count("CA"));
}
TEST(TestFun,TestFindAll)
{
    DnaSeq d1("GCACGCAATCA");
    std::vector<size_t >index;
    index.push_back(1);
    index.push_back(5);
    index.push_back(9);
    ASSERT_EQ(index, d1.findAllSub("CA"));
}
TEST(TestFun,TestFindCon)
{
    DnaSeq d1("ATGATGTGATGA");
    std::vector <DnaSeq> vec;
    vec.push_back("ATGATGTGA");
    vec.push_back("ATGATGTGATGA");
    vec.push_back("ATGTGA");
    vec.push_back("ATGTGATGA");
    ASSERT_EQ(vec, d1.findCon());
}

