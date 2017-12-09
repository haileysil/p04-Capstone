#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

int main()
{
        char input;
        do
        {
                cout<<"\n==RECIPE BOOK MANAGER==";
                cout<<"\nEnter your choice: ";
                cout<<"\n (P)rint Recipe";
                cout<<"\n (C)reate Grocery List;
                cout<<"\n (Q)uit";
                cout<<"\n Your choice (P/C/Q): ";
                cin>>input;

                if (input=='P'||input=='p')
                {
                        cout<<"recipe to screen"<<endl;
                }
                else if (input=='C'||input=='c')
                {
                        vector <ingredient> groceryList;
                        char recipe_name[255];
                        string first;
                        ifstream file;

                        cout <<"What recipe would you like to create a grocery list for? (Must end in .txt)"<<endl;
                        cin>>recipe_name;
                        
                        file.open(recipe_name);
                        
                        if (file.is_open())
                                {
                                        do 
                                        {
                                        //print out first word (Ingredients)
                                        getline(file,first);

                                        //print out each ingredient
                                                ingredient thing;
                                                double num;
                                                myfile>>num;
                                                thing.setAmount(num);

                                                string type;
                                                myfile>>type;
                                                thing.setMeasurement(type);

                                                string item;
                                                myfile>>item;
                                                thing.setName(item);

                                                groceryList.push_back(thing);

                                        }while (file does not read 'Directions') //will need to fix this
                                        file.close();
                                } 
                                else cout<<"unable to open file";
                }

                if (input !='P' && input !='p' && input != 'C' && input != 'c' && input !='Q' && input != 'q') 
                {
                        cout<<"Character entered does not match a menu option. Please try again."<<endl;
                }

        } while (input != 'Q' && input != 'q');

                                        return 0;
}






