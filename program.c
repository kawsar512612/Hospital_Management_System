#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patient
{
    int id;
    char name[100];
    char disease[100];
};

struct doctor
{
    int id;
    char name[100];
    char specialization[100];
};

struct bill
{
    float roomcharge;
    float medicinecharge;
    float servicecharge;
};

void addPatient()
{
    struct patient p;

    FILE *pp = fopen("patient.txt", "ab");

    printf("Enter patients id: ");
    scanf("%d", &p.id);
    printf("Enter patients name: ");
    scanf("%s", p.name);
    printf("Enter patients disease: ");
    scanf("%s", p.disease);

    fwrite(&p, sizeof(p), 1, pp);
    fclose(pp);
    printf("Patients information added successfully \n");
}

void searchPatient()
{
    struct patient p;
    FILE *kk = fopen("patient.txt", "rb");

    int id;
    printf("Enter id for search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, kk))
    {
        if (p.id == id)
        {
            printf("Found: Id: %d | Name: %s | Disease: %s", p.id, p.name, p.disease);
        }
    }
    fclose(kk);
}

void addDoctor()
{
    struct doctor d;
    FILE *kk = fopen("doctor.txt", "ab");

    printf("Enter Doctor id: ");
    scanf("%d", &d.id);
    printf("Enter doctor name: ");
    scanf("%s", d.name);
    printf("Enter doctor specialization: ");
    scanf("%s", d.specialization);

    fwrite(&d, sizeof(d), 1, kk);
    fclose(kk);
}

void searchDoctor()
{
    struct doctor d;
    FILE *kk = fopen("doctor.txt", "rb");

    int id;
    printf("Enter id to search: ");
    scanf("%d", &id);

    while (fread(&d, sizeof(d), 1, kk))
    {
        if (d.id == id)
        {
            printf("Found: Id: %d | Name: %s | Specializaion: %s", d.id, d.name, d.specialization);
        }
    }
    fclose(kk);
}

int main()
{
    int choice;
    do
    {

        printf("\n Hospital Management System \n");
        printf("1. Add Patient \n");
        printf("2. Search Doctor \n");
        printf("3.Add doctor \n");
        printf("4. Search Patient \n");
        printf("5. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    
        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            searchDoctor();
            break;
        case 3:
            addDoctor();
            break;
        case 4:
            searchPatient();
            break;
        case 5:
            printf("Exiting \n");
        default:
            printf("Invalid choice! \n");
        }
    } while (choice != 5);
}
