
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif // _DEBUG

#include "String.h"
#include <string>
#include <iostream>
#include <cassert>
#include <utility>
using namespace std;
//Den här metoden kontrollerar att innehåller i en String-objekt stämmer med C-string(const char* rhs)
void AssertStrEqual(const String &lhs, const char *rhs)
{
    for (size_t i = 0; i < lhs.size() && *rhs != '\0'; ++i) //iterera över alla tecken i String-objektet lhs
    {//loop fortstätter tills i<lhs.size och pekaren rhs pekar på ett tecken som nt är \0 (slutet)
        assert(lhs[i] == rhs[i]); //Jämför tecken lhs och rhs. Om olika tecken -> misslyckas assert
        assert(rhs[i] != 0);//kontrollerar att C-string rhs har giltigt tecken vis position i.
    }
    assert(rhs[lhs.size()] == 0); // Kontrollerar att rhs har nått sitt slut och att den är lika lång som lhs. 
}
//Denna metoden testar reallokering av minnet och push_back.
void TestPushBackReallocation()
{     //Skapar en String instans och lägger till fler tecken i den tills dess kapacitet överskrids. När det händer så kontrolleras att omallokering sker och att den nya kapaciteten är större än den

    String str("hej");
    assert(str.size() <= str.capacity()); // kollar så att str inte överskrider kapaciteten.
    assert(str.size() == 3); //kontrollerar att "hej" str har storlek 3 
    auto hej = "hej"; 
    // AssertStrEqual(str, hej);
    AssertStrEqual(str, "hej");//säkerställer att str och C-sträng hej är identiskA.

    auto internalBuf = &str[0]; //iternalbuf lagrar pekaren till det interna-buffer minnet i str
    auto cap = str.capacity(); 
    auto siz = str.size();
    size_t i;
    for (i = siz + 1; i <= cap; ++i) 
    {
        str.push_back(char(i) + 'a');  //Lägger till ett nytt tecken i slutet av str
        assert(internalBuf == &str[0]); //Försäkrar att str inte har omallokerat sitt interna minne
        assert(cap == str.capacity()); //kontrollerar att kapaciteten inte har förändrats trots push_back
        assert(i == str.size());
    }
    //Push_back ännu ett tecken och triggar en omallokering av interna buffer-minnet. 
    str.push_back(char(i));
    assert(internalBuf != &str[0]);
    assert(cap < str.capacity());
    assert(i == str.size());
}

//Den här metoden kontrollerar att destruktorn för String endast frigör allokerat minne och inte onödiga operationer. 
void TestDelete()
{
    void *sSave = malloc(sizeof(String)); //Malloc - allokera rått minne. Returnerar en pekare till det allokerat minne. 
    void *sPtr;
    {
        String s("hejsan");
        sPtr = &s; //sPtr lagra adress av s
        memcpy(sSave, &s, sizeof(String)); // memcpy - kopierar minnet där s är lagrat till sSave. 
    }
    if (memcmp(sSave, sPtr, sizeof(String))) //memcmp - jämför minnesinnehåll i sSave och sPtr. 
        cout << "You are doing uneccessary things in you deconstructor ~String()\n";  //om memcmp returnerat annat värde än 0 anropas detta. betyder att minnesinnehåller skiljer sig och att destruktorn har gjort annat än att endast frigöra allokera minne)

    free(sSave); //frigör minne
}
//Testar kapaciteten 
void TestCapacitySetting()
{
    {
        String s, r;
        int size = s.size();
        //lägger till fler tecken än vad som ryms i kapaciteten 
        for (int i = 0; i < size * 2 + 16; ++i)
            r.push_back('a' + i % 26);
        s = r;
        assert(s.size() <= s.capacity());
    }
    { // Will probably fail to catch any error :-(
        String r;
        for (int i = 0; i < 65; ++i)
            r.push_back('a' + i % 26); 
        String s(r);
        assert(s.size() <= s.capacity());
    }
}
//Den här metoden testar push_back, fler tecken läggs till i String och kontrollerar att storleken stämmer överens
void TestPushBack()
{
    
        String str = "bar";
        str.push_back('a');
        assert(str == "bara");
    
    
        String r;
        int size = 65;
        for (int i = 0; i < size; ++i)
            r.push_back('a' + i % 26);
        assert(r.size() <= r.capacity());
        assert(r.size() == size);
    
}

void TestFörGodkäntString()
{

    String str0;
    AssertStrEqual(str0, ""); //Jämför en String med en C-string .Kollar om tom sträng har värdet null.

    String s1("foo"); 
    assert(s1 == "foo"); //Kontrollerar om s1 innehåller rätt värde
   
   String str(s1);
    assert(str == "foo"); // Kopieringskonstruktor - kontrollerar om den fungerar 
   
    String s3("bar");
    assert(s3 == "bar");

    delete new String("hej"); //Destruktorn testas - frigör minne
  
    str = "hej";
    assert((str = s3) == s3); //Kopiering av en sträng till en annan sträng
    assert((str = str) == s3); // self assignment - kontrollera att självtilldelning fungerar 

    // Ej samma buffert
    str = "heja";
    s3 = str; 
    str[0] = 'x';
    assert(s3[0] == 'h');  //kontrollerar om s3 har det värde på index 0
    s3[1] = 'y';
    assert(str[1] == 'e');

    String str1("foo"), str2("bar"), str3("hej");
    str3 = str = str1;
    assert(str3 == str); //kedjad tilldelning
    assert(str1 == str);

    TestCapacitySetting(); //testa kapacitet.

    // No extra realloc
    AssertStrEqual(str1, "foo");
    auto xxx = str1.data();  //Ger en pekare till arrayen som innehåller stärngen
    str1 = String("huj");
    assert(xxx == str1.data()); // kollar om data pekar rätt 
    //- operator==
    // testas verallt!
    {
        String s, r;
        s.push_back(0); //lägger till tecken på slutet av strängen 
        s.push_back(0);
        s.push_back(0);
        r.push_back(0);
        assert(s != r && !(r == s)); //kollar om s och r är inte är olika
    }
    //- operator!=
    assert(str1 != str); //Testar != operatoren, 
    assert(!(str1 != str1));
    //- operator[](size_t i) som indexerar utan range check.
    str = "bar";
    str[-1]; //Testa index hantering utanför gränsen
    str[1000]; // No error
    assert(str[1] == 'a'); 
    str[1] = 'y';
    assert(str[1] == 'y');

    const String sc(str); //Const string- testas
    assert(sc[1] == 'y');
    assert(std::is_const<std::remove_reference<decltype(sc[1])>::type>::value); //testar om sc[1] är konstant 

    //Kolla att det blir en const resultat av indexering
    //- push_back(char c)
    TestPushBack(); // push_back testas
    const char *temp = str.data();
    assert(temp == &str[0]); //kollar om data pekar på samma  adress

    //- size(), capacity() and reloccation test;
    TestPushBackReallocation(); //Kollar om reallokering är rätt
    cout << String("hej\n");
    cout << "Om det står hej på föregående rad så är TestFörGodkänt klar\n";
}

int main()
{
 //   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
     locale::global(locale("C"));

     TestFörGodkäntString();

    cout << "G test klart\n";

  
}
