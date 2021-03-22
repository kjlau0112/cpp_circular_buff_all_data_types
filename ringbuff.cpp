#include "ring.h"

int main()
{
    ring<string>textString(5);

    textString.add("one");
    textString.add("two");
    textString.add("three");
    textString.add("four");
    textString.add("five");
    textString.add("six");
    textString.add("seven");

    cout<<"textString.size()"<<textString.size()<<endl;
    for(int i = 0; i<textString.size(); i++)
    {
        cout<<textString.get(i)<<endl;
    }


}