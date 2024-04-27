#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <vector>

using namespace std;

class Product
{
public:
    double price;
    double total;
    string productName;
    int quantity;

    virtual int getOption() = 0;
    virtual void displayMenu() = 0;
    virtual double chooseOpt(int option) = 0;

    void calculateVat(double price, int quantity)
    {
        double localTax = price * 0.02 * quantity;
        double temptotal = localTax + price * quantity;
        double vat = temptotal * 0.13;
        total = vat + temptotal;
    }

    void display()
    {
        cout << fixed << setprecision(2);
        cout << "------------------------------------------------------------------------" << endl;
        cout << setw(5) << "SN" << setw(35) << "Item" << setw(10) << "Quantity" << setw(20) << "Price" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        // Display selected items, quantities, and prices
        cout << setw(5) << "1" << setw(35) << productName << setw(10) << quantity << setw(20) << price * quantity << endl;
        cout << "------------------------------------------------------------------------" << endl;

        // Additional details
        cout << "Local Tax (2%): Rs " << setw(2) << price * 0.02 * quantity << endl;
        cout << "VAT (13%): Rs " << setw(2) << (price * quantity * 0.02 + price * quantity) * 0.13 << endl;
        cout << "Total Bill: Rs " << setw(2) << total << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }

    void saveToFile(string filename, string username, string datetime)
    {
        ofstream outFile(filename, ios::app);
        if (outFile.is_open())
        {
            outFile << fixed << setprecision(2);
            outFile << "------------------------------------------------------------------------" << endl;
            outFile << "                          KEY SHO WOR Electronics" << endl;
            outFile << "------------------------------------------------------------------------" << endl;
            outFile << "Customer Name: " << username << endl;
            outFile << "Date & Time: " << datetime << endl;
            outFile << "------------------------------------------------------------------------" << endl;
            outFile << setw(5) << "SN" << setw(35) << "Item" << setw(10) << "Quantity" << setw(20) << "Price" << endl;
            outFile << "------------------------------------------------------------------------" << endl;
            // Writing selected items, quantities, and prices to file
            outFile << setw(5) << "1" << setw(35) << productName << setw(10) << quantity << setw(20) << price * quantity << endl;
            outFile << "------------------------------------------------------------------------" << endl;

            // Additional details
            outFile << "Local Tax (2%): Rs " << setw(2) << price * 0.02 * quantity << endl;
            outFile << "VAT (13%): Rs " << setw(2) << (price * quantity * 0.02 + price * quantity) * 0.13 << endl;
            outFile << "Total Bill: Rs " << setw(2) << total << endl;
            outFile << "------------------------------------------------------------------------" << endl;

            outFile.close();
        }
        else
        {
            cout << "Unable to open file for saving invoice." << endl;
        }
    }

    void setProductName(string name)
    {
        productName = name;
    }

    void setQuantity(int qty)
    { // Setter for quantity
        quantity = qty;
    }

    double getTotal() const
    {
        return total;
    }
};

class Smartphone : public Product
{
private:
    string names[9] = {"Samsung Galaxy S24 Ultra 12/512GB", " iPhone 15 Pro MAX 8/1TB", "Samsung Galaxy A54 5G 8/128GB ", "Vivo V30 5G 12/256GB", "OnePlus 12 16/512GB", "Redmi Note 13 Pro+ 12/512GB", "Realme GT 2 Pro 12/256GB", "OPPO Reno 10 5G 8/256GB", "Nothing phone 1 8/256GB"};

public:
    int getOption()
    {
        int chooseSmartphone;
        cin >> chooseSmartphone;
        return chooseSmartphone;
    }

    void displayMenu()
    {
        cout << "Smartphone" << endl;
        cout << "1: " << names[0] << " : Rs 1,99,999|-" << endl;
        cout << "2: " << names[1] << " : Rs 2,52,999|-" << endl;
        cout << "3: " << names[2] << " : Rs 56,999" << endl;
        cout << "4: " << names[3] << " : Rs 60,999" << endl;
        cout << "5: " << names[4] << " : Rs 1,39,999" << endl;
        cout << "6: " << names[5] << " : Rs 52,999" << endl;
        cout << "7: " << names[6] << " : Rs 1,09,999" << endl;
        cout << "8: " << names[7] << " : Rs 56,999" << endl;
        cout << "9: " << names[8] << " : Rs 61,999" << endl;
    }

    double chooseOpt(int option)
    {
        switch (option)
        {
        case 1:
            price = 199999;
            productName = names[0];
            break;
        case 2:
            price = 252999;
            productName = names[1];
            break;
        case 3:
            price = 56999;
            productName = names[2];
            break;
        case 4:
            price = 60999;
            productName = names[3];
            break;
        case 5:
            price = 139999;
            productName = names[4];
            break;
        case 6:
            price = 52999;
            productName = names[5];
            break;
        case 7:
            price = 109999;
            productName = names[6];
            break;
        case 8:
            price = 56999;
            productName = names[7];
            break;
        case 9:
            price = 61999;
            productName = names[8];
            break;
        default:
            cout << "Invalid input! Please select from the list" << endl;
            break;
        }
        return price;
    }
};

class Laptop : public Product
{
private:
    string names[9] = {"Dell XPS 15", "Apple M3 MacBook Pro Apple M3", "HP Spectre x360", "Lenevo Legion slim 5", "HP Victus 16", "Asus TUF Gaming A15", "Acer Nitro 5 ", "MSI Katana 15 ", "Gigabyte AORUS 5"};

public:
    int getOption()
    {
        int chooseLaptop;
        cin >> chooseLaptop;
        return chooseLaptop;
    }

    void displayMenu()
    {
        cout << "Laptop" << endl;
        cout << "1: " << names[0] << " : Rs 4,19,999|-" << endl;
        cout << "2: " << names[1] << " : Rs 2,44,999|-" << endl;
        cout << "3: " << names[2] << " : Rs 1,29,999" << endl;
        cout << "4: " << names[3] << " : Rs 1,49,999" << endl;
        cout << "5: " << names[4] << " : Rs 93,999" << endl;
        cout << "6: " << names[5] << " : Rs 1,17,999" << endl;
        cout << "7: " << names[6] << " : Rs 1,24,999" << endl;
        cout << "8: " << names[7] << " : Rs 1,94,999" << endl;
        cout << "9: " << names[8] << " : Rs 2,11,999" << endl;
    }

    double chooseOpt(int option)
    {
        switch (option)
        {
        case 1:
            price = 419999;
            productName = names[0];
            break;
        case 2:
            price = 244999;
            productName = names[1];
            break;
        case 3:
            price = 129999;
            productName = names[2];
            break;
        case 4:
            price = 149999;
            productName = names[3];
            break;
        case 5:
            price = 93999;
            productName = names[4];
            break;
        case 6:
            price = 117999;
            productName = names[5];
            break;
        case 7:
            price = 124999;
            productName = names[6];
            break;
        case 8:
            price = 194999;
            productName = names[7];
            break;
        case 9:
            price = 211999;
            productName = names[8];
            break;
        default:
            cout << "Invalid input! Please select from the list" << endl;
            break;
        }
        return price;
    }
};

class Accessories : public Product
{
private:
    string names[9] = {"Wireless Headphones", "Bluetooth Speaker", "Smartwatch", "RAM 16GB DDR5", "PNY 256FB M.2 NVMe SSD", "Recon Gaming Backpack", "Type C Hub", "RGB Gaming Keyboard", "RGB Gaming Wired Mouse"};

public:
    int getOption()
    {
        int chooseAccessory;
        cin >> chooseAccessory;
        return chooseAccessory;
    }

    void displayMenu()
    {
        cout << "Accessories" << endl;
        cout << "1: " << names[0] << " : Rs 4,999|-" << endl;
        cout << "2: " << names[1] << " : Rs 3,999|-" << endl;
        cout << "3: " << names[2] << " : Rs 9,999" << endl;
        cout << "4: " << names[3] << " : Rs 4,399" << endl;
        cout << "5: " << names[4] << " : Rs 4,799" << endl;
        cout << "6: " << names[5] << " : Rs 11,999" << endl;
        cout << "7: " << names[6] << " : Rs 3,999" << endl;
        cout << "8: " << names[7] << " : Rs 16,999" << endl;
        cout << "9: " << names[8] << " : Rs 2,999" << endl;
    }

    double chooseOpt(int option)
    {
        switch (option)
        {
        case 1:
            price = 4999;
            productName = names[0];
            break;
        case 2:
            price = 3999;
            productName = names[1];
            break;
        case 3:
            price = 9999;
            productName = names[2];
            break;
        case 4:
            price = 4399;
            productName = names[3];
            break;
        case 5:
            price = 4799;
            productName = names[4];
            break;
        case 6:
            price = 11999;
            productName = names[5];
            break;
        case 7:
            price = 3999;
            productName = names[6];
            break;
        case 8:
            price = 16999;
            productName = names[7];
            break;
        case 9:
            price = 2999;
            productName = names[8];
            break;
        default:
            cout << "Invalid input! Please select from the list" << endl;
            break;
        }
        return price;
    }
};

class Gadgets : public Product
{
private:
    string names[3] = {"Drone", "Action Camera", "Fitness Tracker"};

public:
    int getOption()
    {
        int chooseGadget;
        cin >> chooseGadget;
        return chooseGadget;
    }

    void displayMenu()
    {
        cout << "Gadgets" << endl;
        cout << "1: " << names[0] << " : Rs 29,999|-" << endl;
        cout << "2: " << names[1] << " : Rs 15,999|-" << endl;
        cout << "3: " << names[2] << " : Rs 8,999" << endl;
    }

    double chooseOpt(int option)
    {
        switch (option)
        {
        case 1:
            price = 29999;
            productName = names[0];
            break;
        case 2:
            price = 15999;
            productName = names[1];
            break;
        case 3:
            price = 8999;
            productName = names[2];
            break;
        default:
            cout << "Invalid input! Please select from the list" << endl;
            break;
        }
        return price;
    }
};

class PCComponents : public Product
{
private:
    string names[5] = {"MSI GeForce RTX 4090", "16GB DDR5 RAM", "RGB Chassis", "Power Supply", "Intel 13th Gen Core i5 13600K"};

public:
    int getOption()
    {
        int chooseComponent;
        cin >> chooseComponent;
        return chooseComponent;
    }

    void displayMenu()
    {
        cout << "PC Components" << endl;
        cout << "1: " << names[0] << " : Rs 3,19,999|-" << endl;
        cout << "2: " << names[1] << " : Rs 12,999|-" << endl;
        cout << "3: " << names[2] << " : Rs 15,999" << endl;
        cout << "4: " << names[3] << " : Rs 33,999" << endl;
        cout << "5: " << names[4] << " : Rs 53,999" << endl;
    }

    double chooseOpt(int option)
    {
        switch (option)
        {
        case 1:
            price = 319999;
            productName = names[0];
            break;
        case 2:
            price = 12999;
            productName = names[1];
            break;
        case 3:
            price = 15999;
            productName = names[2];
        case 4:
            price = 33999;
            productName = names[3];
        case 5:
            price = 53999;
            productName = names[4];
            break;
        default:
            cout << "Invalid input! Please select from the list" << endl;
            break;
        }
        return price;
    }
};

void printInvoices(const vector<Product *> &items, const string &username, const string &datetime, double totalBill)
{
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                               KEY SHO WOR Electronics" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Customer Name: " << username << endl;
    cout << "Date & Time: " << datetime << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << setw(5) << "SN" << setw(35) << "Item" << setw(10) << "Quantity" << setw(20) << "Price" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < items.size(); ++i)
    {
        cout << setw(5) << i + 1 << setw(35) << items[i]->productName << setw(10) << items[i]->quantity << setw(20) << items[i]->price * items[i]->quantity << endl;
    }
    cout << "---------------------------------------------" << endl;
    cout << "Local Tax (2%): Rs " << setw(2) << (totalBill * 0.02) << endl;
    cout << "VAT (13%): Rs " << setw(2) << (totalBill * 0.13) << endl;
    cout << "Total Bill: Rs " << setw(2) << totalBill << endl;
    cout << "------------------------------------------------------------------------" << endl;

    // Generate invoice
    ofstream outFile("invoice.txt", ios::app); // Append mode
    if (outFile.is_open())
    {
        outFile << fixed << setprecision(2);
        outFile << "------------------------------------------------------------------------" << endl;
        outFile << "                         KEY SHO WOR Electronics" << endl;
        outFile << "------------------------------------------------------------------------" << endl;
        outFile << "Customer Name: " << username << endl;
        outFile << "Date & Time: " << datetime << endl;
        outFile << "------------------------------------------------------------------------" << endl;
        outFile << setw(5) << "SN" << setw(35) << "Item" << setw(10) << "Quantity" << setw(20) << "Price" << endl;
        outFile << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < items.size(); ++i)
        {
            outFile << setw(5) << i + 1 << setw(35) << items[i]->productName << setw(10) << items[i]->quantity << setw(20) << items[i]->price * items[i]->quantity << endl;
        }
        outFile << "------------------------------------------------------------------------" << endl;
        outFile << "Local Tax (2%): Rs " << setw(2) << (totalBill * 0.02) << endl;
        outFile << "VAT (13%): Rs " << setw(2) << (totalBill * 0.13) << endl;
        outFile << "Total Bill: Rs " << setw(2) << totalBill << endl;
        outFile << "------------------------------------------------------------------------" << endl;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file for saving invoice." << endl;
    }
}

int main()
{
    double totalBill = 0;
    string username;
    string datetime;

    // Get current date and time
    time_t now = time(0);
    datetime = ctime(&now);

    // Get customer's name
    cout << "Enter your name: ";
    getline(cin, username);

    vector<Product *> items; // Store selected items

    int choice;
    do
    {
        // Display the main menu
        cout << "Welcome to KEY SHO WOR Electronics" << endl;
        cout << "Please press product id to continue" << endl;
        cout << "1: Smartphone " << endl;
        cout << "2: Laptop " << endl;
        cout << "3: Accessories" << endl;
        cout << "4: Gadgets" << endl;
        cout << "5: PC components" << endl;
        cout << "0: Calculate Bill & Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Product *smartphone = new Smartphone();
            smartphone->displayMenu();
            int smartphoneOption = smartphone->getOption();
            double smartphonePrice = smartphone->chooseOpt(smartphoneOption);

            int qty; // Quantity
            cout << "Enter quantity: ";
            cin >> qty;
            smartphone->setQuantity(qty); // Set quantity

            smartphone->calculateVat(smartphonePrice, qty); // Calculate total with quantity
            smartphone->display();
            totalBill += smartphone->getTotal();
            items.push_back(smartphone);
            break;
        }
        case 2:
        {
            Product *laptop = new Laptop();
            laptop->displayMenu();
            int laptopOption = laptop->getOption();
            double laptopPrice = laptop->chooseOpt(laptopOption);

            int qty; // Quantity
            cout << "Enter quantity: ";
            cin >> qty;
            laptop->setQuantity(qty); // Set quantity

            laptop->calculateVat(laptopPrice, qty); // Calculate total with quantity
            laptop->display();
            totalBill += laptop->getTotal();
            items.push_back(laptop);
            break;
        }
        case 3:
        {
            Product *accessory = new Accessories();
            accessory->displayMenu();
            int accessoryOption = accessory->getOption();
            double accessoryPrice = accessory->chooseOpt(accessoryOption);

            int qty; // Quantity
            cout << "Enter quantity: ";
            cin >> qty;
            accessory->setQuantity(qty); // Set quantity

            accessory->calculateVat(accessoryPrice, qty); // Calculate total with quantity
            accessory->display();
            totalBill += accessory->getTotal();
            items.push_back(accessory);
            break;
        }
        case 4:
        {
            Product *gadget = new Gadgets();
            gadget->displayMenu();
            int gadgetOption = gadget->getOption();
            double gadgetPrice = gadget->chooseOpt(gadgetOption);

            int qty; // Quantity
            cout << "Enter quantity: ";
            cin >> qty;
            gadget->setQuantity(qty); // Set quantity

            gadget->calculateVat(gadgetPrice, qty); // Calculate total with quantity
            gadget->display();
            totalBill += gadget->getTotal();
            items.push_back(gadget);
            break;
        }
        case 5:
        {
            Product *component = new PCComponents();
            component->displayMenu();
            int componentOption = component->getOption();
            double componentPrice = component->chooseOpt(componentOption);

            int qty; // Quantity
            cout << "Enter quantity: ";
            cin >> qty;
            component->setQuantity(qty); // Set quantity

            component->calculateVat(componentPrice, qty); // Calculate total with quantity
            component->display();
            totalBill += component->getTotal();
            items.push_back(component);
            break;
        }
        case 0:
            break; // Exit the loop
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }

        if (choice != 0)
        {
            cout << "Do you want to add another item? (1 for Yes / 0 for No): ";
            cin >> choice;
            while (cin.fail() || (choice != 0 && choice != 1))
            {
                cout << "Invalid input! Please enter 1 for Yes or 0 for No: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> choice;
            }
        }
    } while (choice == 1);

    // Prompt the user to print invoices or exit the program
    cout << "Would you like to print invoices? (1 for Yes / 0 for No): ";
    cin >> choice;
    while (cin.fail() || (choice != 0 && choice != 1))
    {
        cout << "Invalid input! Please enter 1 for Yes or 0 for No: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    if (choice == 1)
    {
        // Print invoices
        printInvoices(items, username, datetime, totalBill);
    }

    // Clean up memory
    for (auto item : items)
    {
        delete item;
    }

    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
