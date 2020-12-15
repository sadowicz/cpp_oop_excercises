#pragma once

class Time {
public:

    void create(bool endless);
    long long now() const;

    void flow();

private:
    long long year;
    bool endless;
};