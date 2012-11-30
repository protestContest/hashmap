#include "gtest/gtest.h"
#include "Hashmap.h"
#include <string>
#include <cmath>
#include <sstream>
using std::string;
using std::stringstream;

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
        stringstream key;
        key << "key" << i;
        ih->insert(key.str(), i);
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->insert(key.str(), sqrt(i));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        sh->insert(key.str(), "string" + i);
    }
    delete sh;
}

TEST(Hashtest, BasicFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(0, ih->find(key.str()));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(0, dh->find(key.str()));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        //EXPECT_EQ(0, sh->find(key.str()));
    }
    delete sh;
}

TEST(Hashtest, BasicRemove) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        ih->remove(key.str());
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->remove(key.str());
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        sh->remove(key.str());
    }
    delete sh;
}

TEST(Hashtest, InsertFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        ih->insert(key.str(), i*3);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i*3, ih->find(key.str()));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->insert(key.str(), i/3);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i/3, dh->find(key.str()));
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        sh->insert(key.str(), "test" + i*3);
    }
    for (int i = 0; i < 10; i+=2) {
        stringstream key;
        key << "key" << i;
    }
    delete sh;
}

TEST(Hashtest, InsertFindRemove) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        ih->insert(key.str(), i*7);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i*7, ih->find(key.str()));
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key, badKey;
        key << "key" << i;
        badKey << "falskey" << i;
        ih->remove(key.str());
        ih->remove(badKey.str());
    }
    delete ih;
    
    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->insert(key.str(), i/7);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i/7, dh->find(key.str()));
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->remove(key.str());
    }
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    for (char i = 'a'; i < 'j'; ++i) {
        sh->insert("ifrtest " + i, i + " test");
    }
    for (int i = 0; i < 10; ++i) {
        //EXPECT_EQ(sh->find("ifrtest" + i), i + "test");
    }
    for (int i = 0; i < 10; ++i) {
        sh->remove("ifrtest" + i);
    }
    delete sh;
}

TEST(Hashtest, InsertFindRemoveFind) {
    Hashmap<int>* ih = new Hashmap<int>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        ih->insert(key.str(), i*13-10);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i*13-10, ih->find(key.str()));
        ih->remove(key.str());
        EXPECT_EQ(0, ih->find(key.str()));
    }
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        dh->insert(key.str(), i/13-10);
    }
    for (int i = 0; i < 10; ++i) {
        stringstream key;
        key << "key" << i;
        EXPECT_EQ(i/13-10, dh->find(key.str()));
        dh->remove(key.str());
        EXPECT_EQ(0, dh->find(key.str()));
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

TEST(Hashtest, CollisionInsert) {
    Hashmap<int>* ih = new Hashmap<int>();
    ih->insert("abc", 1);
    ih->insert("acb", 2);
    ih->insert("bac", 3);
    EXPECT_EQ(2, ih->find("acb"));
    EXPECT_EQ(1, ih->find("abc"));
    EXPECT_EQ(3, ih->find("bac"));
    ih->remove("acb");
    EXPECT_EQ(3, ih->find("bac"));
    EXPECT_EQ(0, ih->find("acb"));
    EXPECT_EQ(1, ih->find("abc"));
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    dh->insert("abc", .1);
    dh->insert("acb", .2);
    dh->insert("bac", .3);
    EXPECT_EQ(.2, dh->find("acb"));
    EXPECT_EQ(.1, dh->find("abc"));
    EXPECT_EQ(.3, dh->find("bac"));
    dh->remove("acb");
    EXPECT_EQ(.3, dh->find("bac"));
    EXPECT_EQ(0, dh->find("acb"));
    EXPECT_EQ(.1, dh->find("abc"));
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    sh->insert("abc", "a");
    sh->insert("acb", "b");
    sh->insert("bac", "c");
    //EXPECT_EQ("b", sh->find("acb"));
    //EXPECT_EQ("a", sh->find("abc"));
    //EXPECT_EQ("c", sh->find("bac"));
    sh->remove("acb");
    //EXPECT_EQ("c", sh->find("bac"));
    //EXPECT_EQ(0, sh->find("acb"));
    //EXPECT_EQ("a", sh->find("abc"));
    delete sh;
}

TEST(Hashtest, DuplicateInsert) {
    Hashmap<int>* ih = new Hashmap<int>();
    ih->insert("string", 1);
    ih->insert("string", 2);
    ih->insert("string", 3);
    EXPECT_EQ(3, ih->find("string"));
    ih->remove("string");
    EXPECT_EQ(0, ih->find("string"));
    delete ih;

    Hashmap<double>* dh = new Hashmap<double>();
    dh->insert("string", .1);
    dh->insert("string", .2);
    dh->insert("string", .3);
    //EXPECT_EQ(.3, dh->find("string"));
    dh->remove("string");
    //EXPECT_EQ(0, dh->find("string"));
    delete dh;

    Hashmap<string>* sh = new Hashmap<string>();
    sh->insert("string", "a");
    sh->insert("string", "b");
    sh->insert("string", "c");
    //EXPECT_EQ("c" sh->find("string"));
    sh->remove("string");
    //EXPECT_EQ(0, sh->find("string"));
    delete sh;
}
