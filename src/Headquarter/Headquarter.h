#ifndef SRC_HEADQUARTER_H
#define SRC_HEADQUARTER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <Provider.h>
#include <Client.h>
#include <Truck.h>
#include <Utils.h>

class Headquarter {
private:
    std::vector<Client *> clients;
    std::vector<Provider *> providers;
    std::vector<Truck *> trucks;
    std::vector<Order *> orders;
    std::vector<Product *> products;
    unsigned int capital;
    Position *address;
    Graph<Position> graph;
    std::string admin_password = "123";
public:

    /**
    * Headquarters constructor
    * @param capital the capital (funds) that the company has
    */
    Headquarter(unsigned int capital);

    //-------------------------GETTERS-------------------------

    /**
    * Gets the Graph of the map that is being used
    *
    * @return the graph of the map
    */
    Graph<Position> getGraph() const;

    /**
    * Gets a specific provider
    *
    * @param id the id of the provider
    * @return the provider wanted if exists, else nullptr
    */
    Provider *getProviderById(unsigned int id);

    /**
    * Gets a specific client
    *
    * @param id the id of the client
    * @return the client wanted if exists, else nullptr
    */
    Client *getClientById(unsigned int id);

    /**
     * Gets order by id
     *
     * @param id id of the order
     * @return the order wanted
     */
    Order *getOrderById(unsigned int id);

    /**
     * Gets product by id
     *
     * @param id the product id
     * @return the product wanted
     */
    Product *getProductById(unsigned int id);

    /**
    * Gets the position in graph with the id specified
    *
    * @param id the id of the position to look for
    * @return the position wanted
    */
    Position getPositionById(double id);

    /**
    * Gets the headquarters admin password
    *
    * @return the admin password
    */
    std::string getAdminPassword() const;

    /**
     * Gets the number of products listed
     *
     * @return the number of products listed
     */
    unsigned int getNProducts() const;

    /**
    * Gets the number of clients
    *
    * @return the number of clients
    */
    unsigned int getNClients() const;

    /**
    * Gets the number of orders
    *
    * @return the number of orders
    */
    unsigned int getNOrders() const;

    /**
    * Gets the number of trucks
    *
    * @return the number of trucks
    */
    unsigned int getNTrucks() const;

    //-------------------------ADDERS-------------------------

    /**
    * Adds a client to the headquarters database
    *
    * @param client to be added
    */
    void addClient(Client *client);

    /**
    * Adds a provider to the headquarters database
    *
    * @param provider to be added
    */
    void addProvider(Provider *provider);

    /**
    * Adds a truck to the headquarters database
    *
    * @param truck to be added
    */
    void addTruck(Truck *truck);

    /**
    * Adds an order to the orders made to the company
    *
    * @param order the order to be added
    */
    void addOrder(Order *order);

    /**
     * Adds a product to headquarters database
     *
     * @param product the product to be added
     */
    void addProduct(Product *product);

    //-------------------------FILE LOADERS & SAVERS-------------------------

    /**
    * Imports map into graph from file
    * @param nodes_path the path to the file where graph nodes are stored
    * @param edges_path the path to the file where graph edges are stored
    */
    void loadMap(const std::string &nodes_path,
                 const std::string &edges_path);

    /**
    * Loads all company data into the program
    *
    * @param clients_path path to the clients file
    * @param providers_path path to the providers file
    * @param trucks_path path to the trucks file
    * @param orders_path path to file of company orders
    * @param products_path path to file of products listed
    */
    void loadAllData(const std::string &clients_path, const std::string &providers_path, const std::string &trucks_path,
                     const std::string &orders_path, const std::string &products_path);

    /**
    * Saves all company data into files
    *
    * @param clients_path path to the clients file
    * @param providers_path path to the providers file
    * @param trucks_path path to the trucks file
    * @param orders_path path to file of company orders
    * @param products_path path to file of products listed
    */
    void saveAllData(const std::string &clients_path, const std::string &providers_path, const std::string &trucks_path,
                     const std::string &orders_path, const std::string &products_path);

    /**
    * Saves all clients data in it respective file
    * @param clients_path the path to the clients file
    */
    void saveClientData(const std::string &clients_path);

    /**
    * Loads all clients data into program
    * @param clients_path the path to the clients file
    */
    void loadClientData(const std::string &clients_path);

    /**
    * Saves all providers data in it respective file
    * @param providers_path the path to the providers file
    */
    void saveProviderData(const std::string &providers_path);

    /**
    * Loads all providers data into program
    * @param providers_path the path to the providers file
    */
    void loadProviderData(const std::string &providers_path);

    /**
    * Saves all trucks data in it respective file
    * @param trucks_path the path to the trucks file
    */
    void saveTruckData(const std::string &trucks_path);

    /**
    * Loads all trucks data into program
    * @param trucks_path the path to the trucks file
    */
    void loadTruckData(const std::string &trucks_path);

    /**
    * Saves all orders data in it respective file
    * @param orders_path the path to the order file
    */
    void saveOrderData(const std::string &orders_path);

    /**
    * Loads all orders data into program
    * @param orders_path the path to the orders file
    */
    void loadOrderData(const std::string &orders_path);

    /**
    * Saves all products data in it respective file
    * @param products_path the path to the products file
    */
    void saveProductData(const std::string &products_path);

    /**
    * Loads all products data into program
    * @param products_path the path to the products file
    */
    void loadProductData(const std::string &products_path);

    //-------------------------DATA SHOWERS-------------------------

    /**
    * Displays products listed to user
    */
    void showProducts();

    /**
    * Displays clients to user
    */
    void showClients();

    /**
    * Shows the providers to the user
    */
    void showProviders();

    /**
    * Displays trucks to user
    */
    void showTrucks();

    /**
    * Displays orders to user
    */
    void showOrders();
};

#endif //SRC_HEADQUARTER_H
