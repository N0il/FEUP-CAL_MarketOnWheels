#include <Headquarter.h>
#include <Menu.h>

/*#include "gtest/gtest.h"
#include "gmock/gmock.h"*/

using namespace std;

int main(int argc, char *argv[]) {
    //Criação de headquarter
    Headquarter headquarter("123");

    headquarter.loadMap("../src/Resources/nodes.txt", "../src/Resources/edges.txt");
    headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                            "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                            "../src/Resources/products.txt");

    std::cout << "|||||||| Market On Wheels ||||||||" << std::endl << std::endl;

    //------------------------ CREATING MENUS ------------------------

    //Main Menu
    Menu main_menu = Menu("Choose your user category");
    main_menu.addOption("Client");
    main_menu.addOption("Provider");
    main_menu.addOption("Admin");
    main_menu.addOption("Register");

    Menu admin_menu = Menu("Administration");
    //admin_menu.addOption("Import Data");  //TODO discuss if it is correct in here
    admin_menu.addOption("Save Data");
    admin_menu.addOption("Calculate optimized paths");  //calculate the optimized paths for each truck
    admin_menu.addOption("Deliver");  //removes all orders that were in the trucks from system
    admin_menu.addOption("Show Trucks");
    admin_menu.addOption("Show Clients");
    admin_menu.addOption("Show Providers");
    admin_menu.addOption("Buy Truck");

    //Register menu
    Menu register_menu = Menu("Register");
    register_menu.addOption("Client");
    register_menu.addOption("Provider");

    bool exit = false;
    while(!exit){
        main_menu.show();
        unsigned int user_category = main_menu.getInput();
        switch (user_category) {
            //exit option
            case 0: {
                cout << "Goodbye! And thanks for your visit!\n" << std::endl;
                exit = true;
                break;
            }
            //client area
            case 1: {
                cout << "Client area\n" << std::endl;
                break;
            }
            //provider area
            case 2:{
                cout << "Provider area\n" << std::endl;
                break;
            }
            //admin area
            case 3: {
                cout << "Administration area\n" << std::endl;
                admin_menu.show();
                unsigned int option = admin_menu.getInput();
                switch (option) {
                    //Save Data
                    case 1 :{
                        headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                                                "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                                                "../src/Resources/products.txt");
                        break;
                    }
                    //Calculated optimized paths
                    case 2 :{
                        break;
                    }
                    //Deliver
                    case 3 :{
                        break;
                    }
                    //Show Trucks
                    case 4 :{
                        headquarter.showTrucks();
                        break;
                    }
                    //Show clients
                    case 5 :{
                        headquarter.showClients();
                        break;
                    }
                    //Show providers
                    case 6 :{
                        headquarter.showProviders();
                        break;
                    }
                    case 7:{
                        cout << "What's the capacity?\n";
                        int capacity; cin >> capacity;
                        if(capacity <= 0){
                            cout << "Invalid capacity\n";
                        }
                        else headquarter.addTruck(new Truck(capacity));
                        break;
                    }
                }
                break;
            }
            //register area
            case 4: {
                cout << "Registration area\n" << std::endl;
                register_menu.show();
                unsigned int type = register_menu.getInput();
                switch (type) {
                    case 1: {
                        cout << "Client \n";
                        cout << "Hello Client\n";

                        cout << "What's your name?\n";
                        string name; cin >> name;
                        cout << "What's your user name?\n";
                        string userName; cin >> userName;

                        Date date;
                        cout << "Input your birthdate with format: dd/mm/yyyy" << std::endl;
                        cin >> date;

                        cout << "What's your address id?\n";
                        double address;
                        cin >> address;

                        if(headquarter.clientSearcher(userName)){
                            cout << "You already exist in our company\n";
                            break;
                        }

                        if(!headquarter.positionSearcher(address)){
                            cout << "We can't deliver into you're address\n";
                            break;
                        }

                        headquarter.addClient(new Client(name, userName, date, address));
                        break;
                    }
                    case 2: {
                        cout << "Provider \n";

                        cout << "What's your name?\n";
                        string name; cin >> name;
                        cout << "What's your user name?\n";
                        string userName; cin >> userName;
                        //TODO ver a questão da morada
                        if(!headquarter.providerSearcher(userName)){
                            headquarter.addProvider(new Provider(name, userName));
                        }
                        else{
                            cout << "You're already registered!\n";
                        }
                        break;
                    }
                }

                break;
            }
        }
    }

    headquarter.saveAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                            "../src/Resources/trucks.txt", "../src/Resources/orders.txt",
                            "../src/Resources/products.txt");

    //TODO destrutor para a headquarters
}

/*
    Menu client_menu = Menu("Client's Area");
    client_menu.addOption("Make Order");
    client_menu.addOption("Cancel Order");
    client_menu.addOption("Show info");

    Menu providers_menu = Menu("Provider's Area");
    providers_menu.addOption("Add product");
    providers_menu.addOption("Remove Product");
    providers_menu.addOption("Add Quantity to product");
    providers_menu.addOption("Remove Quantity to product");
    providers_menu.addOption("Show info");
*/

    /*       case 1: {*/
                /*unsigned int client_id;
                std::cout << "Enter your client id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> client_id;
                    if (client_id == 0) {
                        exit = true;
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getClientById(client_id) == nullptr);
                unsigned int client_option;*/
               /* if (!exit) {
                    client_menu.show();
                    client_option = client_menu.getInput();
                }

                switch (client_option) {
                    case 1: {
                        break;
                    }
                    case 2: {
                        break;
                    }
                    case 3: {
                        break;
                    }
                }
                break;*/
//            }
            //provider area

/* testing::InitGoogleTest(&argc, argv);
    std::cout << "\n\n----------MARKETONWHEELS TESTS----------" << std::endl;
    return RUN_ALL_TESTS();*/

/*
 *  std::cout << "Importing data into program structures..." << std::endl;
                        headquarter.loadAllData("../src/Resources/clients.txt", "../src/Resources/providers.txt",
                                                "../src/Resources/trucks.txt", "src/Resources/orders.txt",
                                                "../src/Resources/products.txt");*/

/*unsigned int provider_id;
                std::cout << "Enter your provider id: " << std::endl;
                do {
                    std::cout << "->";
                    std::cin >> provider_id;
                    if (provider_id == 0) {
                        exit = true;
                        break;
                    }
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } while (std::cin.fail() || headquarter.getProviderById(provider_id) == nullptr);*/