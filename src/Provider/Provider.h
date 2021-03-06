#ifndef SRC_PROVIDER_H
#define SRC_PROVIDER_H

#include <map>
#include "../ProductsWrapper/ProductsWrapper.h"

class Provider : public ProductsWrapper {
private:
    unsigned int id;

    /**
    * Id auxiliar to unique provider id
    */
    static unsigned int id_aux;
    std::string name;
    std::string user_name;
    unsigned int position_id;
    long double dist = 0;  //used to calculate minimal path of trucks
public:
    /**
     * Void constructor for provider
     */
    Provider();

    /**
     * Simple constructor for provider
     *
     * @param name the providers name
     * @param user_name the user name for provider
     * @param position_id address of provider
     */
    Provider(std::string name, std::string user_name, unsigned int position_id);

    /**
    * Provider constructor
    *
    * @param name the name of the distributor (company)
    * @param user_name the user name of the provider (user to use than name)
    * @param products the stock of the provider products
    * @param position_id the address of the provider
    */
    Provider(std::string name, std::string user_name, std::map<Product *, unsigned int> products, unsigned int position_id);

    /**
    * Gets provider id
    *
    * @return the provider id
    */
    unsigned int getId() const;

    /**
    * Sets the provider name
    *
    * @param name the provider name
    */
    void setName(const std::string& name);

    /**
    * Gets the name of the provider
    *
    * @return the provider's name
    */
    std::string getName() const;

    /**
    * Sets the provider user name
    *
    * @param user_name the user name of the provider
    */
    void setUserName(const std::string& user_name);

    /**
    * Gets the provider user name
    *
    * @return the user name of the provider
    */
    std::string getUserName() const;

    /**
     * Sets the position_id (address) or provider
     * @param position_id the address to be set
     */
    void setAddress(unsigned int position_id);

    /**
     * Gets the position_id of provider (address)
     * @return the position_id of provider
     */
    unsigned int getAddress() const;

    /**
     * Sets the dist from headquarter to the provider
     */
     void setDist(long double dist);

     /**
      * Gets the distance from headquarter to provider
      */
      long double getDist() const;

    /**
    * Overload to << operator of Provider
    *
    * @param os the output stream to be outputted
    * @param provider the provider object
    * @return the output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Provider& provider);

    /**
    * Overload to operator >> of Provider
    * @param is the input stream to be outputted
    * @param provider the provider object
    * @return the input stream
    */
    friend std::istream& operator>>(std::istream& is, Provider& provider);
};

#endif //SRC_PROVIDER_H
