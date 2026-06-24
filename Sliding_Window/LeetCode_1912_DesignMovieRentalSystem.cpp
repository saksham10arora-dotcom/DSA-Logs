```cpp
// Design Movie Rental System, https://leetcode.com/problems/design-movie-rental-system/
// You are given a movie rental system that has n movies and m stores. 
// Each movie can be rented from any number of stores, and each store can have multiple copies of a movie.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class MovieRentalSystem {
public:
    MovieRentalSystem(int n, int m) : movie_to_store(n), store_to_movie(m) {}

    void rent(int movie, int store, int price) {
        // Brute force approach: O(m) complexity to find the store with the lowest price for the movie
        // Optimal solution: O(1) complexity using a map to store the rented movies
        movie_to_store[movie].insert({store, price});
        store_to_movie[store].insert({movie, price});
        rented_movies.insert({price, {movie, store}});
    }

    void drop(int movie, int store) {
        // Brute force approach: O(m) complexity to find the store with the lowest price for the movie
        // Optimal solution: O(1) complexity using a map to store the rented movies
        movie_to_store[movie].erase({store, get_price(movie, store)});
        store_to_movie[store].erase({movie, get_price(movie, store)});
        for (auto it = rented_movies.begin(); it != rented_movies.end(); ++it) {
            if (it->second.first == movie && it->second.second == store) {
                rented_movies.erase(it);
                break;
            }
        }
    }

    std::vector<int> search(int movie) {
        // Brute force approach: O(m) complexity to find all stores with the movie
        // Optimal solution: O(m) complexity using a map to store the stores with the movie
        std::vector<int> result;
        for (auto it = movie_to_store[movie].begin(); it != movie_to_store[movie].end(); ++it) {
            result.push_back(it->first);
        }
        std::sort(result.begin(), result.end(), [this, movie](int a, int b) {
            return get_price(movie, a) < get_price(movie, b);
        });
        return result;
    }

    std::vector<int> search_in_store(int store) {
        // Brute force approach: O(n) complexity to find all movies in the store
        // Optimal solution: O(n) complexity using a map to store the movies in the store
        std::vector<int> result;
        for (auto it = store_to_movie[store].begin(); it != store_to_movie[store].end(); ++it) {
            result.push_back(it->first);
        }
        std::sort(result.begin(), result.end(), [this, store](int a, int b) {
            return get_price(a, store) < get_price(b, store);
        });
        return result;
    }

    std::vector<std::pair<int, int>> report() {
        // Brute force approach: O(m*n) complexity to find all rented movies
        // Optimal solution: O(m) complexity using a set to store the rented movies
        std::vector<std::pair<int, int>> result;
        for (auto it = rented_movies.begin(); it != rented_movies.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }

private:
    std::map<int, std::set<std::pair<int, int>>> movie_to_store;
    std::map<int, std::set<std::pair<int, int>>> store_to_movie;
    std::set<std::pair<int, std::pair<int, int>>> rented_movies;

    int get_price(int movie, int store) {
        for (auto it = movie_to_store[movie].begin(); it != movie_to_store[movie].end(); ++it) {
            if (it->first == store) {
                return it->second;
            }
        }
        return -1;
    }
};

int main() {
    MovieRentalSystem movie_rental_system(3, 3);
    movie_rental_system.rent(0, 0, 10);
    movie_rental_system.rent(0, 1, 15);
    movie_rental_system.rent(1, 0, 20);
    movie_rental_system.rent(2, 1, 25);
    movie_rental_system.rent(2, 2, 30);

    std::vector<int> result1 = movie_rental_system.search(0);
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> result2 = movie_rental_system.search_in_store(0);
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::pair<int, int>> result3 = movie_rental_system.report();
    for (auto i : result3) {
        std::cout << "(" << i.first << ", " << i.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
```