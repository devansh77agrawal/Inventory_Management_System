#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Product 
{
    int id;
    string name;
    int quantity;
    float price;    
};

// Add New Product in Inventory
void addProduct(Product inventory[], int &size) 
{
    if(size<10000) 
	{     
        cout << "Enter id of the product: ";
        cin >> inventory[size].id;
        cout << "Enter name of the product: ";
        cin >> inventory[size].name;
        cout << "Enter quantity of the product: ";
        cin >> inventory[size].quantity;
        cout << "Enter price of the product: ";
        cin >> inventory[size].price;
        size++;
        cout<<"Product added successfully!\n";
    } 
	else 
	{
        cout<<"Inventory full!\n";
    }
}

// Display all Items in the inventory
void displayProduct(const Product inventory[], int size) 
{
    cout<<"Inventory: \n";
    cout<<setw(5)<<"ID";
	cout<<setw(20)<<"Name";
	cout<<setw(10)<<"Quantity";
	cout<<setw(10)<<"Price"<<endl;
	
    for (int i = 0; i < size; ++i) 
	{
        cout<<setw(5)<<inventory[i].id; 
		cout<<setw(20)<<inventory[i].name; 
		cout<<setw(10)<<inventory[i].quantity; 
		cout<<setw(10)<<"Rs."<<inventory[i].price<<endl;
    }
}

// Delete Product from Inventory
void deleteProduct(Product inventory[], int &size, int productId) 
{
    int index = -1;
    for(int i = 0; i < size; ++i) 
	{
        if(inventory[i].id == productId) 
		{
            index = i;
            break;
        }
    }
    if(index != -1) 
	{
        for(int i = index; i < size - 1; ++i) 
		{
            inventory[i] = inventory[i + 1];
        }
        size--;
        cout<<"Product deleted successfully!\n";
    } else 
	{
        cout<<"Product not found!\n";
    }
}

// Modify Product in inventory
void modifyProduct(Product inventory[], int size, int productId) 
{
    int index = -1;
    for(int i = 0; i < size; i++) 
	{
        if(inventory[i].id == productId) 
		{
            index = i;
            break;
        }
    }
    if(index != -1) 
	{
        cout<<"Edit id of product: ";
        cin>>inventory[index].id;
        cout<<"Edit name of the product: ";
        cin>>inventory[index].name;
        cout<<"Edit quantity of the product: ";
        cin>>inventory[index].quantity;
        cout<<"Edit price of the product: ";
        cin>>inventory[index].price;
        cout<<"Product modified successfully!\n";
    } 
	else 
	{
        cout<<"Product not found!\n";
    }
}

// Receipt Generator
void generateReceipt(const Product inventory[], int size) 
{
    float total = 0.0;
    
    cout<<"Receipt:\n";
    cout<<setw(20)<<"Name";
	cout<<setw(10)<<"Quantity"; 
	cout<<setw(10)<<"Price";
	cout<<setw(15)<<"Total"<< endl;
	
    for (int i = 0; i < size; ++i) 
	{
        float subtotal = inventory[i].quantity * inventory[i].price;
        total += subtotal;
        cout<<setw(20)<<inventory[i].name;
		cout<<setw(10)<<inventory[i].quantity; 
		cout<<setw(10)<<"Rs."<<inventory[i].price;
		cout<<setw(15)<<"Rs."<<subtotal << endl;
    }
    cout<<"Total: Rs."<<total<<endl;
}

int main() 
{
    int size;
    cout<<"Enter inventory size: ";
    cin>>size;
    Product inventory[size];
    int choice;

    while(true) 
	{
        cout<<"Enter your choice:\n";
        cout<<"1. Add Product\n";
        cout<<"2. Display Inventory\n";
        cout<<"3. Delete Product\n";
        cout<<"4. Modify Product\n";
        cout<<"5. Generate Receipt\n";
        cout<<"6. Exit\n";
        cin>>choice;

        switch(choice) 
		{
            case 1:
                addProduct(inventory, size);
                break;
            case 2:
                displayProduct(inventory, size);
                break;
            case 3:
                int deleteId;
                cout<<"Enter product Id to delete: ";
                cin>>deleteId;
                deleteProduct(inventory, size, deleteId);
                break;
            case 4:
                int modifyId;
                cout<<"Enter product ID to modify: ";
                cin>>modifyId;
                modifyProduct(inventory, size, modifyId);
                break;
            case 5:
                generateReceipt(inventory, size);
                break;
            case 6:
                cout<<"Exiting...\n";
                return 0;
            default:
                cout<<"Invalid Choice! Operation not possible.\n";
        }
    }
    return 0;
}

