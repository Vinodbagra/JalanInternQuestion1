#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

class coffee_house{
    private:
    const string name[3] ={"Espresso","Cappuccino","Latte"};
    const string addons[3] = {"Milk","Cream","Latte"};
    const int price[3][3] = {{60,75,100},{80,90,125},{100,125,150}};
    map< pair < int, int >, int > items;
    public:
    coffee_house(){
        cout<<string(15,'*')<<"Welcome to Shiru Cafe"<<string(15,'*')<<"\n\n"<<endl;
        cout<<string(20,'=')<<" Menu "<<string(20,'=')<<endl<<endl;
        cout<<"\t"<<left<<setw(25)<<"Coffee with Add-On"<<left<<setw(9)<<"| Price"<<endl;
        cout<<"\t"<<string(34,'-')<<endl;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout<<"\t"<<left<<setw(25)<<name[i]+" with "+addons[j]<<left<<setw(2)<<"|"<<right<<setw(5)<<price[i][j]<<endl;
            }
        }
        cout<<endl;
    }

    bool placeoreder(){
        int Variety;
        int add_on;
        int Quantity;
        cout<<"Choose your Coffee:\n1. Espresso\n2. Cappuccino\n3. Latte\nEnter Choice: ";
        do{

            cin>>Variety;
            if(Variety<1 || Variety>3){
                cout<<"Invalid Input!! Please enter again(1/2/3): ";
            }
            else break;
        }
        while(1);
        cout<<"\nChoose Your Add-On:\n1. Milk\n2. Cream\n3. Latte\nEnter Choice: ";
        do{

            cin>>add_on;
            if(add_on<1 || add_on>3){
                cout<<"Invalid Input!! Please enter again(1/2/3): ";
            }
            else break;
        }
        while(1);
        cout<<"Please Enter Quantity: ";
        cin>>Quantity;
        items[make_pair(Variety-1,add_on-1)]+= Quantity;
        cout<<"Do you want to add on your order(Y/N): ";
        char decide;
        do{

            cin>>decide;
            if(decide == 'N'){
                return true;
            }
            else if(decide != 'Y') cout<<"Invalid Input!! Please enter again(Y/N): ";
            else return false;
        }
        while(1);
    }

    ~coffee_house(){
        int total = 0;
        cout<<"\nThanks for the Visit. Please Visit Again!!\n\nHere is your Bill\n";
        cout<<"\t  "<<string(43,'_')<<endl;
        cout<<"\t |"<<string(43,' ')<<'|'<<endl;
        cout<<"\t |"<<left<<setw(20)<<"Item Name"<<left<<setw(7)<<"| Price"<<left<<setw(6)<<" | Qty."<<left<<setw(6)<<" | Amount|"<<endl
            <<"\t |"<<string(43,'-')<<'|'<<endl;
        for(auto it : items){
            cout<<"\t |"<<left<<setw(20)<<name[(it.first).first]+" with "+addons[(it.first).second]
                <<left<<setw(2)<<"|"<<right<<setw(5)<<price[(it.first).first][(it.first).second]
                <<left<<setw(3)<<" |"<<right<<setw(4)<<it.second
                <<left<<setw(3)<<" |"<<right<<setw(6)<<it.second*price[(it.first).first][(it.first).second]
                <<"|"<<endl;
            total += it.second*price[(it.first).first][(it.first).second];
        }
        cout<<"\t |"<<string(43,' ')<<'|'<<endl
            <<"\t |"<<string(43,'~')<<'|'<<endl
            <<"\t |Total Amount:"<<right<<setw(30)<<total<<'|'<<endl
            <<"\t |"<<string(43,'_')<<"|\n\n\n\n\n"<<endl;

    }

};



int main(){
    coffee_house shiru_cafe;
    
    cout<<"Place Your Order\n"<<endl;
    do{

        bool break_loop = shiru_cafe.placeoreder();
        if(break_loop) break;
    }
    while(1);

    return 0;
}
