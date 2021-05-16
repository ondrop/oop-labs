#include "pch.h"
#include "../task1/CHttpUrl.cpp"
#include "../task1/CUrlParsingError.cpp"

using namespace std;

TEST(Test_CHttpUrl_constructor, Given_correct_url)
{
    CHttpUrl httpUrl("http://example.com/document");
    EXPECT_EQ(httpUrl.GetProtocol(), Protocol::HTTP);
    EXPECT_EQ(httpUrl.GetPort(), 80);
    EXPECT_EQ(httpUrl.GetDomain(), "example.com");
    EXPECT_EQ(httpUrl.GetDocument(), "document");
}

TEST(Test_CHttpUrl_constructor, Given_correct_url_with_port)
{
    CHttpUrl httpUrl("http://localhost:8000/document");
    EXPECT_EQ(httpUrl.GetProtocol(), Protocol::HTTP);
    EXPECT_EQ(httpUrl.GetPort(), 8000);
    EXPECT_EQ(httpUrl.GetDomain(), "localhost");
    EXPECT_EQ(httpUrl.GetDocument(), "document");
}

TEST(Test_CHttpUrl_constructor, Given_correct_url_with_incorrect_port)
{
    EXPECT_THROW(new CHttpUrl("http://localhost:0/document"), CUrlParsingError);
    EXPECT_THROW(new CHttpUrl("http://localhost:65536/document"), CUrlParsingError);
    EXPECT_THROW(new CHttpUrl("ftp://localhost:8000/document"), CUrlParsingError);
}

TEST(Test_CHttpUrl_constructor, Given_incorrect_url)
{
    EXPECT_THROW(CHttpUrl httpUrl("httpppp://example.com/document"), CUrlParsingError);    
}

TEST(Test_CHttpUrl_constructor, Given_domain_and_document_and_protocol)
{
    CHttpUrl httpUrl("example.com", "document", Protocol::HTTPS);
    EXPECT_EQ(httpUrl.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(httpUrl.GetPort(), 443);
    EXPECT_EQ(httpUrl.GetDomain(), "example.com");
    EXPECT_EQ(httpUrl.GetDocument(), "document");
}

TEST(Test_CHttpUrl_constructor, Given_domain_and_document_and_protocol_and_correct_port)
{
    CHttpUrl httpUrl("example.com", "document", Protocol::HTTPS, 8000);
    EXPECT_EQ(httpUrl.GetProtocol(), Protocol::HTTPS);
    EXPECT_EQ(httpUrl.GetPort(), 8000);
    EXPECT_EQ(httpUrl.GetDomain(), "example.com");
    EXPECT_EQ(httpUrl.GetDocument(), "document");
}

TEST(Test_CHttpUrl_methods, Test_GetUrl_method)
{
    CHttpUrl httpUrl1("example.com", "document", Protocol::HTTPS, 8000);
    EXPECT_EQ(httpUrl1.GetURL(), "https://example.com:8000/document");

    CHttpUrl httpUrl2("example.com", "document", Protocol::HTTPS);
    EXPECT_EQ(httpUrl2.GetURL(), "https://example.com/document");

    CHttpUrl httpUrl3("example.com", "document", Protocol::HTTPS, 443);
    EXPECT_EQ(httpUrl3.GetURL(), "https://example.com/document");
}

TEST(Test_CHttpUrl_methods, Test_toString_method)
{
    CHttpUrl httpUrl("example.com", "document", Protocol::HTTPS, 8000);
    stringstream expectedStr;
    expectedStr << PROTOCOL << HTTPS << endl;
    expectedStr << URL_DOMAIN << "example.com" << endl;
    expectedStr << PORT << 8000 << endl;
    expectedStr << DOCUMENT << "document";

    EXPECT_EQ(httpUrl.toString(), expectedStr.str());
}

