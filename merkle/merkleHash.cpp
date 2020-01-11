#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
#include "../Hash/hashFunction.h"

std::string create_merkle(std::vector<std::string>& merkle)
{
    // Stop if hash list is empty or contains one element
    if (merkle.empty())
        return "";
    else if (merkle.size() == 1)
        return merkle[0];

    // While there is more than 1 hash in the list, keep looping...
    while (merkle.size() > 1)
    {
        // If number of hashes is odd, duplicate last hash in the list.
        if (merkle.size() % 2 != 0)
            merkle.push_back(merkle.back());
        // List size is now even.
        assert(merkle.size() % 2 == 0);

        // New hash list.
        std::vector<std::string> new_merkle;
        // Loop through hashes 2 at a time.
        for (auto it = merkle.begin(); it != merkle.end(); it += 2)
        {
            // Join both current hashes together (concatenate).
            std::string concat_data;
            std::string concat;
            concat += *it;
            concat += (*(it + 1));
            // Hash both of the hashes.
            std::string new_root = hashFunc(concat_data);
            // Add this to the new list.
            new_merkle.push_back(new_root);
        }
        // This is the new list.
        merkle = new_merkle;
    }
    // Finally we end up with a single item.
    return merkle[0];
}
