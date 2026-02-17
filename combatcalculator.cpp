#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string ability;
    float damage;
    char abilCat;
    float areaDamage;
    float normDamage;

    cout<<setw(40)<<setfill('-')<<"---"<<endl;
    cout<<"----- Amazing Combat Calculator v1 -----"<<endl;
    cout<<setw(40)<<setfill('-')<<"---"<<endl;

    cout<<"Enter an ability name: ";
    getline(cin,ability);

    if(ability=="Slap")
    {
        cout<<"Enter base damage: ";
        cin>>damage;
        damage = float(damage);
        if(float(damage)<=0)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Damage cannot be negative"<<endl;
            }
        else if(float(damage)>9000)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Only goku can do more than 9000 damage"<<endl;
            }
        else
        {
            cout<<"Enter ability category: ";
            cin>>abilCat;
            cin.ignore();
            switch (abilCat)
            {
            case 'A':
            areaDamage=float(damage)/4;
            cout<<endl<<ability<<" dealt "<<areaDamage<<" area of effect damage to all targets."<<endl;
            break;

            case 'N':
            normDamage=float(damage)*1.2;
            cout<<endl<<ability<<" dealt "<<normDamage<<" normal damage to the target"<<endl;
            break;

            case 'H':
            damage=float(damage)*-1;
            cout<<endl<<ability<<" dealt "<<damage<<" damage healing the target."<<endl;
            break;

            default:
            cout<<endl<<"Ability Category "<<abilCat<<" not implemented yet."<<endl;
            break;
            }

        }
    }
        
    else if(ability=="Rest")
    {
        cout<<"Enter base damage: ";
        cin>>damage;
        damage = float(damage);
        if(float(damage)<=0)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Damage cannot be negative"<<endl;
            }
        else if(float(damage)>9000)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Only goku can do more than 9000 damage"<<endl;
            }
        else
        {
            cout<<"Enter ability category: ";
            cin>>abilCat;
            cin.ignore();
            switch (abilCat)
            {
            case 'A':
            areaDamage=float(damage)/4;
            cout<<endl<<ability<<" dealt "<<areaDamage<<" area of effect damage to all targets."<<endl;

            break;

            case 'N':
            normDamage=float(damage)*1.2;
            cout<<endl<<ability<<" dealt "<<normDamage<<" normal damage to the target"<<endl;
            break;

            case 'H':
            damage=float(damage)*-1;
            cout<<endl<<ability<<" dealt "<<float(damage)<<" damage healing the target."<<endl;

            break;

            default:
            cout<<endl<<"Ability Category "<<abilCat<<" not implemented yet."<<endl;
            break;
            }
        }
    }

    else if(ability=="FrostFire")   
    {
        cout<<"Enter base damage: ";
        cin>>damage;
        damage=float(damage);
        if(float(damage)<=0)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Damage cannot be negative"<<endl;
            }
        else if(damage>9000)
            {
            cout<<"Enter ability category: ";
            cin.get();
            cout<<endl<<"Only goku can do more than 9000 damage"<<endl;
            }
        else
        {
            cout<<"Enter ability category: ";
            cin>>abilCat;
            cin.ignore();
            switch (abilCat)
                {
            case 'A':
            areaDamage=float(damage)/4;
            cout<<endl<<ability<<" dealt "<<areaDamage<<" area of effect damage to all targets."<<endl;
            break;

            case 'N':
            normDamage=float(damage)*1.2;
            cout<<endl<<ability<<" dealt "<<normDamage<<" normal damage to the target"<<endl;
            break;

            case 'H':
            damage=float(damage)*-1;
            cout<<endl<<ability<<" dealt "<<damage<<" damage healing the target."<<endl;
            break;

            default:
            cout<<endl<<"Ability Category "<<abilCat<<" not implemented yet."<<endl;
            break;
            }
        }
    }
      

    else{
        cout<<"Enter base damage: ";
        cin>>damage;
        cin.ignore();
        cout<<"Enter ability category: ";
        cin.get();
        cout<<endl<<"Ability "<<ability<<" not implemented yet."<<endl;}
    
    return 0;
}