
#ifndef PROYECT_PARSE_H
#define PROYECT_PARSE_H
#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <iostream>


#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"

#include <fstream>
#include <cmath>
using namespace rapidjson;

struct City {
    int id;
    string name;
    double latitude;
    double longitude;

    City() {}
    City(int id, const string &name, double latitude, double longitude) : id(id), name(name), latitude(latitude), longitude(longitude) {}
};

struct Airport {
    string id;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;

    Airport() {}

    Airport(string id, const string &name, const string &city, const string &country, double latitude, double longitude) : id(id), name(name), city(city), country(country), latitude(latitude),
                                                                                                                        longitude(longitude) {}


};

enum file {
    pe, airports
};

class Parser {
private:
    Document document;
    string path;
public:
    Parser() = default;

    void generateJson(file json_file = pe);

    void generateUndirectedGraph(UnDirectedGraph<Airport, double> &graph);

    void generateDirectedGraph(DirectedGraph<Airport, double> &graph);

    double euclideanDistance(double latitude1, double longitude1, double latitude2, double longitude2);

    void clear();

    string getPath();

};

void Parser::generateJson(file json_file) {
    path = json_file == airports ? "airports" : "pe";
    ifstream file("../Parser/Data/"+ path + ".json", ifstream::in);
    string json = "";
    string line;
    if (file.is_open()) {
        while (file >> line) {
            json += line;
        }
    } else
        throw("File didn't open correctly");
    document.Parse(json.c_str());
    //cout<<json.c_str()<<endl;
}

double Parser::euclideanDistance(double latitude1, double longitude1, double latitude2, double longitude2){
    return  sqrt(pow((latitude1 - latitude2), 2)  +
                 pow((longitude1 - longitude2), 2));
}

void Parser::generateUndirectedGraph(UnDirectedGraph<Airport, double> &graph) {
    for (Value &airport: document.GetArray()) {
        string airportId = airport["AirportID"].GetString();
        string name = airport["Name"].GetString();
        string city = airport["City"].GetString();
        string country = airport["Country"].GetString();
        double latitude = std::stod(airport["Latitude"].GetString());
        double longitude = std::stod(airport["Longitude"].GetString());
        Airport airportItem(airportId, name, city, country, latitude, longitude);
        try { graph.insertVertex(airportId, airportItem); } catch (...) {
            throw ("Error, Vertex not added");
        }
    }
    for (Value &airport: document.GetArray()) {
        for (Value &destination: airport["destinations"].GetArray()) {
            // cout<<"airport id"<<" "<<airport["AirportID"].GetString()<<endl;
            // cout<<"destination id"<<" "<<destination.GetString()<<endl;
            string idVertexA = airport["AirportID"].GetString();
            string idVertexB = destination.GetString();
            cout << graph[idVertexA].latitude << endl;
            double latitude1 = graph[airport["AirportID"].GetString()].latitude;
            double latitude2 = graph[destination.GetString()].latitude;
            double longitude1 = graph[airport["AirportID"].GetString()].longitude;
            double longitude2 = graph[destination.GetString()].longitude;
            double weight = euclideanDistance(latitude1, longitude1, latitude2, longitude2);
            //cout<<weight<<endl;
            try { graph.createEdge(idVertexA, idVertexB, weight); } catch (...){
                throw ("Error, Edge not created");
            }


        }
    }
}
void Parser::generateDirectedGraph(DirectedGraph<Airport, double> &graph) {
    for (Value &airport: document.GetArray()) {
        string airportId = airport["AirportID"].GetString();
        string name = airport["Name"].GetString();
        string city = airport["City"].GetString();
        string country = airport["Country"].GetString();
        double latitude = std::stod(airport["Latitude"].GetString());
        double longitude = std::stod(airport["Longitude"].GetString());
        Airport airportItem(airportId, name, city, country, latitude, longitude);
        try { graph.insertVertex(airportId, airportItem); } catch (...) {
            throw ("Error, Vertex not added");
        }
    }
    //Creating edges
    for (Value &airport: document.GetArray()) {
        for (Value &destination: airport["destinations"].GetArray()) {
            // cout<<"airport id"<<" "<<airport["AirportID"].GetString()<<endl;
            // cout<<"destination id"<<" "<<destination.GetString()<<endl;
            string idVertexA = airport["AirportID"].GetString();
            string idVertexB = destination.GetString();
            cout << graph[idVertexA].latitude << endl;
            double latitude1 = graph[airport["AirportID"].GetString()].latitude;
            double latitude2 = graph[destination.GetString()].latitude;
            double longitude1 = graph[airport["AirportID"].GetString()].longitude;
            double longitude2 = graph[destination.GetString()].longitude;
            double weight = euclideanDistance(latitude1, longitude1, latitude2, longitude2);
            //cout<<weight<<endl;
            try { graph.createEdge(idVertexA, idVertexB, weight); } catch (...){
                throw ("Error, Edge not created");
            }


        }
    }
}

void Parser::clear() {
    document.Clear();
}

string Parser::getPath() {
    return path;
}

#endif //PROYECT_PARSE_H
