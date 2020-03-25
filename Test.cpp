//
// Created by shira on 24/03/2020.
//
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


/////////////////Test extreme state/////////////////

TEST_CASE("Test - empty word") {
    string text = "Hello World";
        CHECK_THROWS(find(text, ""));
        CHECK_THROWS(find(text, "  "));
}

TEST_CASE("Test - empty text") {
    string text = "";
        CHECK_THROWS(find(text, "hi"));
}

TEST_CASE("Test - not found word") {
    string text = "Hello World";
        CHECK_THROWS(find(text, "bye"));
        CHECK_THROWS(find(text, "ballet"));
}

TEST_CASE("Test - null word") {
    string text = "Hello World";
        CHECK_THROWS(find(text, NULL));
}

TEST_CASE("Test - null text") {
    string text = NULL;
        CHECK_THROWS(find(text, "hi"));
}

TEST_CASE("Test - word with space") {
    string text = "ab cd";
        CHECK_THROWS(find(text, "a b"));
        CHECK_THROWS(find(text, "c d"));
}

TEST_CASE("Test - double word") {
    string text1 = "DO be or not to Be";
            CHECK(find(text1, "to") == string("DO"));
            CHECK(find(text1, "fe") == string("be"));
            CHECK(find(text1, "Fe") == string("be"));
    string text2 = "I like Very wery much to travel";
            CHECK(find(text2, "wery") == string("Very"));
            CHECK(find(text2, "very") == string("Very"));
            CHECK(find(text2, "WERY") == string("Very"));
            CHECK(find(text2, "weri") == string("Very"));
}

TEST_CASE("Test - half word") {
    string text = "There are two kinds of people in this world";
            CHECK_THROWS(find(text, "Ther"));
            CHECK_THROWS(find(text, "feopl"));
            CHECK_THROWS(find(text, "wurl"));
            CHECK_THROWS(find(text, "ky"));
}

TEST_CASE("Test - spaces before or after the word") {
    string text = "There are two kinds of people in this world";
            CHECK(find(text, "   There") == string("There"));
            CHECK(find(text, "feuble  ") == string("people"));
            CHECK(find(text, " thyz ") == string("this"));
}

TEST_CASE("Test - spaces in the text") {
    string text = "There      are      two    kinds  of   people    in    this    world";
            CHECK(find(text, "There") == string("There"));
            CHECK(find(text, "feuble") == string("people"));
            CHECK(find(text, "  thyz") == string("this"));
}

/////////////////Test of replaces between c <--> k <--> q /////////////////

TEST_CASE("Test replacement of c to k") {
    string text = "Cute cat";
            CHECK(find(text, "Cute") == string("Cute"));
            CHECK(find(text, "kute") == string("Cute"));
            CHECK(find(text, "cat") == string("cat"));
            CHECK(find(text, "kat") == string("cat"));
}

TEST_CASE("Test replacement of c to q") {
    string text = "Cute cat";
            CHECK(find(text, "qat") == string("cat"));
            CHECK(find(text, "qute") == string("Cute"));
}

TEST_CASE("Test replacement of k to q") {
    string text = "The king of the world";
            CHECK(find(text, "king") == string("king"));
            CHECK(find(text, "qing") == string("king"));
}

TEST_CASE("Test replacement of k to c") {
    string text = "The king of the world";
            CHECK(find(text, "cing") == string("king"));
}

TEST_CASE("Test replacement of q to k") {
    string text = "Lets be quiet";
            CHECK(find(text, "quiet") == string("quiet"));
            CHECK(find(text, "kuiet") == string("quiet"));
}

TEST_CASE("Test replacement of q to c") {
    string text = "Lets be quiet";
            CHECK(find(text, "cuiet") == string("quiet"));
}


/////////////////Test of replaces between b <--> f <--> p /////////////////

TEST_CASE("Test replacement of p to b") {
    string text = "happy";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of p to f") {
    string text = "happy";
            CHECK(find(text, "haffy") == string("happy"));
            CHECK(find(text, "hapfy") == string("happy"));
            CHECK(find(text, "hafpy") == string("happy"));
}

TEST_CASE("Test replacement of b to p") {
    string text = "baby";
            CHECK(find(text, "baby") == string("baby"));
            CHECK(find(text, "paby") == string("baby"));
            CHECK(find(text, "bapy") == string("baby"));
            CHECK(find(text, "papy") == string("baby"));
}

TEST_CASE("Test replacement of b to f") {
    string text = "baby";
            CHECK(find(text, "faby") == string("baby"));
            CHECK(find(text, "bafy") == string("baby"));
            CHECK(find(text, "fafy") == string("baby"));
}

TEST_CASE("Test replacement of f to b") {
    string text = "fight";
            CHECK(find(text, "fight") == string("fight"));
            CHECK(find(text, "bight") == string("fight"));
}

TEST_CASE("Test replacement of f to p") {
    string text = "fight";
            CHECK(find(text, "pight") == string("fight"));
}

/////////////////Test of replaces between v <--> w /////////////////

TEST_CASE("Test replacement of v to w") {
    string text = "The view is wonderful";
            CHECK(find(text, "view") == string("view"));
            CHECK(find(text, "wiew") == string("view"));
}

TEST_CASE("Test replacement of w to v") {
    string text = "The view is wonderful";
            CHECK(find(text, "wonderful") == string("wonderful"));
            CHECK(find(text, "vonderful") == string("wonderful"));
}

/////////////////Test of replaces between g <--> j /////////////////

TEST_CASE("Test replacement of g to j") {
    string text = "Google is not a joke";
            CHECK(find(text, "Google") == string("Google"));
            CHECK(find(text, "joogle") == string("Google"));
            CHECK(find(text, "Goojle") == string("Google"));
            CHECK(find(text, "joojle") == string("Google"));
}

TEST_CASE("Test replacement of j to g") {
    string text = "Google is not a joke";
            CHECK(find(text, "joke") == string("joke"));
            CHECK(find(text, "goke") == string("joke"));
}

/////////////////Test of replaces between s <--> z /////////////////

TEST_CASE("Test replacement of s to z") {
    string text = "Shoshana love very much cola zero";
            CHECK(find(text, "Shoshana") == string("Shoshana"));
            CHECK(find(text, "zhoshana") == string("Shoshana"));
            CHECK(find(text, "Shozhana") == string("Shoshana"));
            CHECK(find(text, "zhozhana") == string("Shoshana"));
}

TEST_CASE("Test replacement of z to s") {
    string text = "Shoshana love very much cola zero";
            CHECK(find(text, "zero") == string("zero"));
            CHECK(find(text, "sero") == string("zero"));
}

/////////////////Test of replaces between d <--> t /////////////////

TEST_CASE("Test replacement of t to d") {
    string text = "This is not the time to start a diet";
            CHECK(find(text, "This") == string("This"));
            CHECK(find(text, "dime") == string("time"));
            CHECK(find(text, "nod") == string("not"));
            CHECK(find(text, "stard") == string("start"));
}

TEST_CASE("Test replacement of d to t") {
    string text = "This is not the time to start a diet";
            CHECK(find(text, "diet") == string("diet"));
            CHECK(find(text, "tiet") == string("diet"));
}

/////////////////Test of replaces between o <--> u /////////////////

TEST_CASE("Test replacement of o to u") {
    string text = "Do not go outside because of the corona";
            CHECK(find(text, "uotside") == string("outside"));
            CHECK(find(text, "coruna") == string("corona"));
            CHECK(find(text, "nut") == string("not"));
            CHECK(find(text, "Du") == string("Do"));
}

TEST_CASE("Test replacement of u to o") {
    string text = "Do not go outside because of the corona";
            CHECK(find(text, "outside") == string("outside"));
            CHECK(find(text, "ootside") == string("outside"));
            CHECK(find(text, "becaose") == string("because"));
}

/////////////////Test of replaces between i <--> y /////////////////

TEST_CASE("Test replacement of i to y") {
    string text = "I love you";
            CHECK(find(text, "i") == string("I"));
            CHECK(find(text, "y") == string("I"));
}

TEST_CASE("Test replacement of y to i") {
    string text = "I love you";
            CHECK(find(text, "you") == string("you"));
            CHECK(find(text, "iou") == string("you"));
}

/////////////////Test replacement of lower-case and upper-case/////////////////

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "DoNt WoOrY bE hApPy";
            CHECK(find(text, "DoNt") == string("DoNt"));
            CHECK(find(text, "dOnT") == string("DoNt"));
            CHECK(find(text, "dont") == string("DoNt"));
            CHECK(find(text, "DONT") == string("DoNt"));

            CHECK(find(text, "WoOrY") == string("WoOrY"));
            CHECK(find(text, "wOoRy") == string("WoOrY"));
            CHECK(find(text, "woory") == string("WoOrY"));
            CHECK(find(text, "WOORY") == string("WoOrY"));

            CHECK(find(text, "bE") == string("bE"));
            CHECK(find(text, "Be") == string("bE"));
            CHECK(find(text, "be") == string("bE"));
            CHECK(find(text, "BE") == string("bE"));

            CHECK(find(text, "hApPy") == string("hApPy"));
            CHECK(find(text, "HaPpY") == string("hApPy"));
            CHECK(find(text, "HAPPY") == string("hApPy"));
            CHECK(find(text, "happy") == string("hApPy"));
}

/////////////////Finally - Mary Poppins test/////////////////

TEST_CASE("Mary Poppins test") {
    string text = "Try this word supercalifragilisticexpialidocious";
            CHECK(find(text, "SoFerCalyBrajylIzdizexfialYtuciuos") == string("supercalifragilisticexpialidocious"));
}

