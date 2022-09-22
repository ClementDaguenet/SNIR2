#ifndef IPV4_H
#define IPV4_H

class IPv4
{
private:
    unsigned char * adresse;
    unsigned char * masque;
    void CalculerMasque(unsigned char _cidr);
public:
    IPv4(const unsigned char *_adresse, const unsigned char *_masque);
    IPv4(const unsigned char *_adresse, const unsigned char _cidr);
    ~IPv4();
    void ObtenirMasque(unsigned char *_masque);
    void ObtenirAdresseReseau(unsigned char *_reseau);
    void ObtenirAdresseDiffusion(unsigned char *_diffusion);
    void ObtenirPremiereAdresse(unsigned char *_premiereAdresse);
    void ObtenirDerniereAdresse(unsigned char *_derniereAdresse);
    int ObtenirNombreDeMachines();
};

#endif // IPV4_H
