#include <iostream>
#include <vector>
using namespace std;

class Series {
    string name;
    vector<double> values;

public:
    Series();
    ~Series();
    void append(double value);
    double& operator[](int index);
    Series& operator+=(const Series& other);
    friend ostream& operator<<(ostream& os, const Series& s);
};

ostream& operator<<(ostream& os, const Series& s);

class Histogram {
    vector<Series> series_list;

public:
    Histogram();
    ~Histogram();
    void add_series(string name);
    Series& operator[](const string& str);
    friend ostream& operator<<(ostream& os, const Histogram& h);
    vector<string> get_series_names() const;
};

Series::Series() {

}

Series::~Series() {

}

void Series::append(double value) {
    values.push_back(value);
}

double& Series::operator[](int index) {
    if (index < 0 || index >= values.size()) {
        throw out_of_range("Index out of range");
    }
    return values[index];
}

Series& Series::operator+=(const Series& other) {
    int min_size = min(values.size(), other.values.size());
    for (int i = 0; i < min_size; ++i) {
        values[i] += other.values[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, const Series& s) {
    os << s.name << endl;
    for (const auto& value : s.values) {
        os << value << endl;
    }
    return os;
}

Histogram::Histogram() {
    
}

Histogram::~Histogram() {
   
}

void Histogram::add_series(string name) {
    Series new_series;
    new_series.name = name;
    series_list.push_back(new_series);
}

Series& Histogram::operator[](const string& str) {
    for (auto& series : series_list) {
        if (series.name == str) {
            return series;
        }
    }
    throw invalid_argument("Series not found");
}

ostream& operator<<(ostream& os, const Histogram& h) {
    for (const auto& series : h.series_list) {
        os << series << endl;
    }
    return os;
}

vector<string> Histogram::get_series_names() const {
    vector<string> names;
    for (const auto& series : series_list) {
        names.push_back(series.name);
    }
    return names;
}
