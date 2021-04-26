#include <iostream>
using namespace std;

/*
    Inheritance - IV
    Question : Model a hierarchy of phones using inheritance
    Ans: We'll assume we have three types of phones - Land line Phone, Mobile Phone, Smart Phone
         We model Helper classes
         We model each phone separately
         We model the phone hierarchy

    class PhoneNumber; //12-digit phone number
    class Name;        //Subscriber Name(as string)
    class Photo;       //Image and Subscriber Name as alt text
    class RingTone;    //Audio and ring tone name
    class Contact;     //PhoneNumber, Name, Photo (optional) of a contact
    class AddressBook; //List of contacts

    See blow : That's how you answer a design pattern question
    MobilePhone ----ISA----> LandlinePhone
    SmartPhone  ----ISA----> MobilePhone
*/

//Abstract phone (Later we will study this as well)
class Phone {
public:
    virtual void call(const PhoneNumber *p) = 0;
    virtual void Answer() = 0;
    virtual void Redial() = 0;
}

class LandLinePhone { //public Phone
    PhoneNumber number_;
    Name subscriber_;
    RingTone rTone_;

public:
    LandLinePhone(const string num, const string subs);
    void Call(const PhoneNumber* p);
    void Answer();

    friend ostream& operator<<(ostream& os, const LandLinePhone& p); //for debugging if reuired
};

//Nokia 1100
class MobilePhone {  // : public LandlinePhone (is we do this, we can comment common member functions)
    PhoneNumber number_; //This
    Name subscriber_;    //This all can be inherited from LandlinePhone
    RingTone rTone_;     //This

    AddressBook aBook_;
    PhoneNumber *lastDial_;
    void setLastDialed(const PhoneNumber& p); //It's internal to phone, so it's private (implementation)
    void showNumber();

public:
    //These form the interface (user see)
    MobilePhone(const string num, const string subs);
    void Call(PhoneNumber* p); //Can call by number
    void Call(const Name& n);  //Can call by name as well (number will come from AddressBook which will return phone number for name)
    void Answer(); //This can also commented if we inherit LandlinePhone

    void Redial(); //Redial the number that I had dialled last
    void SetRingTone(RingTone::RINGTONE r);
    void AddContact(const string num = "", const string subs = "");

    friend ostream& operator<<(ostream& os, const MobilePhone& p); //for debugging if reuired
};


//Smart Phone (it can call by touch screen)
class SmartPhone { //public MobilePhone can be done as well and we can then remove many APIs from below
    PhoneNumber number_;
    Name subscriber_;
    RingTone rTone_;

    AddressBook aBook_;
    PhoneNumber *lastDial_;
    void setLastDialed(const PhoneNumber& p); //It's internal to phone, so it's private (implementation)
    void showNumber();

    unsigned int size_; //7inch display, etc
    void DIsplayPhoto();

public:
    //These form the interface (user see)
    SmartPhone(const string num, const string subs);
    void Call(PhoneNumber* p); //Can call by number using touchscreen
    void Call(const Name& n);  //Can call by name as well (number will come from AddressBook which will return phone number for name)
    void Answer();

    void Redial(); //Redial the number that I had dialled last
    void SetRingTone(RingTone::RINGTONE r);
    void AddContact(const string num = "", const string subs = "");

    friend ostream& operator<<(ostream& os, const SmartPhone& p); //for debugging if reuired
};
