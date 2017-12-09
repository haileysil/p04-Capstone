#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ingredient.h"

using namespace std;

int main()
{
        vector <string> recipes;

        string cookies,enchiladas,meatloaf,muffins,omelet;

        recipes.push_back("cookies");
        recipes.push_back("enchiladas");
        recipes.push_back("meatloaf");
        recipes.push_back("muffins");
        recipes.push_back("omelet");

        char input;

        do
        {
                cout<<"\n==RECIPE BOOK MANAGER==";
                cout<<"\nEnter your choice: ";
                cout<<"\n (R)ead Recipe";
                cout<<"\n (C)reate Grocery List";
                cout<<"\n (P)rint Grocery List";
                cout<<"\n (Q)uit";
                cout<<"\n Your choice (R/C/P/Q): ";
                cin>>input;

                if (input=='R'||input=='r')
                {
                        string line;
                        ifstream FileToScreen;
                        char recipe_name[255];

                        cout<<"What recipe would you like to read?"<<endl;
                        cout<<"Your choices are: "<<endl;

                        for (int i=0; i < recipes.size(); i++)
                        {
                                cout<<recipes[i]<<endl;
                        }
                        cout<<"Your choice must end with '.txt'"<<endl;

                        cin>>recipe_name;

                        FileToScreen.open(recipe_name);

                        if (FileToScreen.is_open())
                        {
                                while ( getline (FileToScreen,line) )
                                {
                                        cout<<line<<endl;
                                }
                                FileToScreen.close();
                        }
                        else 
                        {
                                cout<< "Unable to open file"<<endl;
                        } 

                }

                else if (input=='C'||input=='c')
                {
                        char recipe_name[255];
                        vector <ingredient> groceryList; 
                        string first_word;
                        ifstream file;

                        cout<<"What recipe would you like to create a grocery list for?"<<endl;
                        cout<<"Your choices are: "<<endl;
                        for (int i=0; i < recipes.size(); i++)
                        {
                                cout<<recipes[i]<<endl;
                        }
                        cout<<"Your choice must end with '.txt'"<<endl;

                        cin>>recipe_name;

                        file.open(recipe_name);

                        if (file.is_open())
                        {
                                do
                                {
                                        ingredient thing;

                                        double num;
                                        file>>num;
                                        thing.setAmount(num);

                                        string type;
                                        file>>type;
                                        thing.setMeasurement(type);

                                        string item;
                                        file>>item;
                                        thing.setName(item);

                                        groceryList.push_back(thing);

                                } while (file.peek() != '#');

                                file.close();
                        }
                        else 
                        {
                                cout<<"unable to open file";
                        }
                }

                if (input=='p'||input=='P')
                {
                        cout<<"Grocery List:"<<endl;

                        for (int i=0; i<groceryList.size(); i++)
                        {
                                cout<<groceryList[i]<<endl;
                        }
                }

                if (input !='R' && input !='r' && input != 'C' && input != 'c' && input=='P' && input=='p' && input !='Q' && input != 'q') 
                {
                        cout<<"Character entered does not match a menu option. Please try again."<<endl;
                }

        } while (input != 'Q' && input != 'q');

        return 0;
}
