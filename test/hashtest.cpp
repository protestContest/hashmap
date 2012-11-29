#include "gtest/gtest.h"
#include "Hashmap.h"
#include <string>
#include <cmath>
using std::string;

TEST(Hashtest, Constructor) {
    Hashmap<int>* i = new Hashmap<int>();
    Hashmap<double>* d = new Hashmap<double>();
    Hashmap<string>* s = new Hashmap<string>();

    delete i;
    delete d;
    delete s;
}

TEST(Hashtest, BasicInsert) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        ih->insert("key" + i, i);
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        dh->insert("key" + i, sqrt(i));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        sh->insert("key" + i, "string" + i);
    }
    delete sh;
}

TEST(Hashtest, BasicFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(0, ih->find("string" + i));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(0, dh->find("string" + i));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        //EXPECT_EQ(sh->find("string" + i), 0);
    }
    delete sh;
}

TEST(Hashtest, BasicRemove) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        ih->remove("string" + i);
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        dh->remove("string" + i);
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        sh->remove("string" + i);
    }
    delete sh;
}

TEST(Hashtest, InsertFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        ih->insert("iftest" + i, i*3);
    }
    for (int i = 0; i < 10; i+=2) {
        EXPECT_EQ(i*3, ih->find("iftest" + i));
    }
    for (int i = 1; i < 10; i+=2) {
        EXPECT_EQ(i*3, ih->find("iftest" + i));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        dh->insert("iftest" + i, i/3);
    }
    for (int i = 0; i < 10; i+=2) {
        EXPECT_EQ(i/3, dh->find("iftest" + i));
    }
    for (int i = 1; i < 10; i+=2) {
        EXPECT_EQ(i/3, dh->find("iftest" + i));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        sh->insert("iftest" + i, "test" + i*3);
    }
    for (int i = 0; i < 10; i+=2) {
        //EXPECT_EQ(sh->find("iftest" + i), "test" + i*3);
    }
    for (int i = 1; i < 10; i+=2) {
        //EXPECT_EQ(sh->find("iftest" + i), "test" + i*3);
    }
    delete sh;
}

TEST(Hashtest, InsertFindRemove) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        ih->insert("ifrtest" + i, i*4);
    }
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(i*4, ih->find("ifrtest" + i));
    }
    for (int i = 999; i >= 0; --i) {
        ih->remove("ifrtest" + i);
    }
    delete ih;
    
    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        dh->insert("ifrtest" + i, i/7);
    }
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(i/7, dh->find("ifrtest" + i));
    }
    for (int i = 999; i >= 0; --i) {
        dh->remove("ifrtest" + i);
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        sh->insert("ifrtest" + i, i + "test");
    }
    for (int i = 0; i < 10; ++i) {
        //EXPECT_EQ(sh->find("ifrtest" + i), i + "test");
    }
    for (int i = 999; i >= 0; --i) {
        sh->remove("ifrtest" + i);
    }
    delete sh;
}

TEST(Hashtest, InsertFindRemoveFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        ih->insert("ifrftest" + i, i*13-10);
    }
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(i*3-10, ih->find("ifrftest" + i));
        ih->remove("ifrftest" + i);
        EXPECT_EQ(0, ih->find("ifrftest" + i));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        dh->insert("ifrftest" + i, i/13-10);
    }
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(i/13-10, dh->find("ifrftest" + i));
        dh->remove("ifrftest" + i);
        EXPECT_EQ(0, dh->find("ifrftest" + i));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        sh->insert("ifrftest" + i, "a" + i);
    }
    for (int i = 0; i < 10; ++i) {
        //EXPECT_EQ(sh->find("ifrftest" + i), "a" + i + "b");
        sh->remove("ifrftest" + i);
        //EXPECT_EQ(sh->find("ifrftest" + i), 0);
    }
    delete sh;
}

