#pragma once
 
class Masina {
    private:
        char* numePosesor, * nrInmatriculare, * status;
    public:
        Masina();
        Masina(const char*,const char*,const char*);
        Masina(const Masina&);
        Masina& operator=(const Masina&);
        char* getNumePosesor();
        char* getNrInmatriculare();
        char* getStatus();
        void setNumePosesor(const char*);
        void setNrInmatriculare(const char*);
        void setStatus(const char*);
        bool operator==(const Masina&);
        ~Masina();
};
