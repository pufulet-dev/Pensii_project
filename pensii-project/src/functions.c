#include <emscripten.h>
#include <bits/stdc++.h> 

EMSCRIPTEN_KEEPALIVE


// pension calculator

float calculatePensieLimitaDeVarsta(std::chrono::time_point<std::chrono::system_clock> dataPensionare,
                                    char gen,
                                    int varstaPensionare,
                                    int varstaPensionareBarbati,
                                    int varstaPensionareFemei,
                                    int cotizare1,
                                    int cotizare2,
                                    double venitLunar) {
    // difference in years
    const auto inputDate = dataPensionare;
    const auto today = std::chrono::system_clock::now();
    const auto diffMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(today - inputDate).count();
    const auto diffYears = diffMilliseconds / (1000.0 * 60 * 60 * 24 * 365.25);
    auto pensReala = varstaPensionare;
    
    auto stagiuMinim = (gen == 'M') ? 39 : 37;
    auto varstaPensionareActuala = (gen == 'M') ? varstaPensionareBarbati : varstaPensionareFemei;

    result = (
        (0.014 * 30 +
        0.02 * (cotizare1 + cotizare2 - stagiuMinim) +
        0.02 * (pensReala - varstaPensionareActuala)) *
        venitLunar
    );
    return result;
}

float calculatePensieInvaliditate(char gen,
                                    int varstaPensionareBarbati,
                                    int varstaPensionareFemei,
                                    char gradDizabilitate,
                                    int cotizare,
                                    double venitLunar) {
    auto pensionare = (gen == 'M') ? varstaPensionareBarbati : varstaPensionareFemei;
    auto stagiuTotal = pensionare - 18;
    if (gradDizabilitate == 'I') {
        result = (
            0.42 * venitLunar +
            (cotizare / stagiuTotal) * venitLunar * 0.1
        );
    } else if (gradDizabilitate == 'II') {
        result = (
            0.35 * venitLunar +
            (cotizare / stagiuTotal) * venitLunar * 0.1
        );
    } else if (gradDizabilitate == 'III') {
        result = (
            0.2 * venitLunar +
            (cotizare / stagiuTotal) * venitLunar * 0.1
        );
    }
    return result;
}

float calculatePensieUrmas(int nrUrmasi, double valoarePensiePredecesor) {
    if (nrUrmasi == 1) {
        result = valoarePensiePredecesor * 0.5;
    } else if (nrUrmasi == 2) {
        result = valoarePensiePredecesor * 0.75;
    } else {
        result = valoarePensiePredecesor;
    }
    return result;
}

float calculatePensieAviatiaCivila(double venitLunar) {
    result = venitLunar * 0.35;
    return result;
}

float calculatePensieDomeniulCulturii(int aniActivitate, std::string domeniuActivitate) {
    if (aniActivitate >= 20 && domeniuActivitate == "1") {
        result = 1;
    } else if (aniActivitate >= 25 && domeniuActivitate == "2") {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}


// performing sorting

typedef struct {
    char name[50];
    char surname[50];
    char gender;
    char idnp[14]; 
    char dob[11];  // date of birth
    float pensionValue;
} Person;

// function to compare two Person structs based on the specified criteria
int compare(const void *a, const void *b, int ascending, int sortBy) {
    const Person *person1 = (const Person *)a;
    const Person *person2 = (const Person *)b;

    int result = 0;

    switch (sortBy) {
        case 1:  // Sort by name
            result = strcmp(person1->name, person2->name);
            break;
        case 2:  // Sort by IDNP
            result = strcmp(person1->idnp, person2->idnp);
            break;
        case 3:  // Sort by pension value
            if (person1->pensionValue < person2->pensionValue) {
                result = -1;
            } else if (person1->pensionValue > person2->pensionValue) {
                result = 1;
            }
            break;
        default:
            printf("Invalid sort criteria\n");
            exit(EXIT_FAILURE);
    }

    return ascending ? result : -result;
}

// function to perform Tournament Sort
void tournamentSort(Person *arr, int size, int ascending, int sortBy) {
    // another function to find the winner index in a tournament
    int tournamentWinnerIndex(Person *arr, int n) {
        int i, winnerIndex = 0;
        for (i = 1; i < n; i++) {
            if (compare(&arr[i], &arr[winnerIndex], ascending, sortBy) > 0) {
                winnerIndex = i;
            }
        }
        return winnerIndex;
    }

    // performing the tournament sort
    int n = size;
    while (n > 1) {
        int m = (n + 1) / 2; // the no of matches
        for (int i = 0; i < m; i++) {
            int winnerIndex = tournamentWinnerIndex(&arr[i * 2], (i == m - 1 && n % 2 == 1) ? 1 : 2);
            if (winnerIndex != 0) {
                // swapping arr[i] and arr[i + winnerIndex]
                Person temp = arr[i];
                arr[i] = arr[i + winnerIndex];
                arr[i + winnerIndex] = temp;
            }
        }
        n = m;
    }
}