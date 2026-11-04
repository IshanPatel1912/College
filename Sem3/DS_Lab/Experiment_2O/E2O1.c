#include <stdio.h>
#include <string.h>

struct patient {
    int p_id;
    char p_name[50];
    int p_age;
    char gender[10];
    char contactNumber[15];
    char disease[50];
    char admissionStatus[15];
};

struct department {
    int d_id;
    char d_name[50];
    struct patient patients[10];
    int currentPatientCount;
};

int isDuplicateDeptId(struct department depts[], int currentDeptCount, int idToCheck) {
    for (int i = 0; i < currentDeptCount; i++) {
        if (depts[i].d_id == idToCheck) {
            return 1;
        }
    }
    return 0;
}

int isDuplicatePatientId(struct department depts[], int currentDeptIndex, int currentPatientIndex, int idToCheck) {
    for (int i = 0; i < currentDeptIndex; i++) {
        for (int j = 0; j < depts[i].currentPatientCount; j++) {
            if (depts[i].patients[j].p_id == idToCheck) {
                return 1;
            }
        }
    }
    for (int j = 0; j < currentPatientIndex; j++) {
        if (depts[currentDeptIndex].patients[j].p_id == idToCheck) {
            return 1;
        }
    }
    return 0;
}


void getData(struct department depts[], int deptCount, int patientCount) {
    int i, j;
    int tempDeptId, tempPatientId;

    for(i = 0; i < deptCount; i++) {
        printf("=== Enter Details of Department %d ===\n", i + 1);
        printf("Enter Department Name: ");
        scanf(" %[^\n]", depts[i].d_name);

        do {
            printf("Enter Department ID: ");
            scanf("%d", &tempDeptId);
            if (isDuplicateDeptId(depts, i, tempDeptId)) {
                printf("Error: Department ID %d already exists! Please try a different ID.\n", tempDeptId);
            } else {
                depts[i].d_id = tempDeptId;
                break;
            }
        } while(1);

        depts[i].currentPatientCount = 0;

        for(j = 0; j < patientCount; j++) {
            printf("\n  -- Enter Details of Patient %d of %s --\n", j + 1, depts[i].d_name);
            printf("  Enter Patient Name: ");
            scanf(" %[^\n]", depts[i].patients[j].p_name);

            do {
                printf("  Enter Patient ID: ");
                scanf("%d", &tempPatientId);
                if (isDuplicatePatientId(depts, i, j, tempPatientId)) {
                    printf("  Error: Patient ID %d already exists in the system! Try another.\n", tempPatientId);
                } else {
                    depts[i].patients[j].p_id = tempPatientId;
                    break;
                }
            } while(1);

            printf("  Enter Age: ");
            scanf("%d", &depts[i].patients[j].p_age);
            printf("  Enter Gender: ");
            scanf(" %[^\n]", depts[i].patients[j].gender);
            printf("  Enter Contact Number: ");
            scanf(" %[^\n]", depts[i].patients[j].contactNumber);
            printf("  Enter Disease: ");
            scanf(" %[^\n]", depts[i].patients[j].disease);
            printf("  Enter Admission Status (Admitted/Not Admitted): ");
            scanf(" %[^\n]", depts[i].patients[j].admissionStatus);

            depts[i].currentPatientCount++;
        }
        printf("\n");
    }
}


void dispData(struct department depts[], int deptCount){
    int i,j;
    for(i = 0; i < deptCount; i++) {
        printf("\n=============================================\n");
        printf("Department Name : %s\n", depts[i].d_name);
        printf("Department ID   : %d\n", depts[i].d_id);
        printf("Total Patients  : %d\n", depts[i].currentPatientCount);
        printf("---------------------------------------------\n");

        if(depts[i].currentPatientCount == 0) {
            printf("No patients registered in this department.\n");
            continue;
        }

        printf("%-6s | %-20s | %-4s | %-8s | %-12s | %-15s | %-12s\n",
               "ID", "Name", "Age", "Gender", "Contact", "Disease", "Status");
        printf("--------------------------------------------------------------------------------------------\n");

        for(j = 0; j < depts[i].currentPatientCount; j++) {
            printf("%-6d | %-20s | %-4d | %-8s | %-12s | %-15s | %-12s\n",
                   depts[i].patients[j].p_id,
                   depts[i].patients[j].p_name,
                   depts[i].patients[j].p_age,
                   depts[i].patients[j].gender,
                   depts[i].patients[j].contactNumber,
                   depts[i].patients[j].disease,
                   depts[i].patients[j].admissionStatus);
        }
    }
    printf("\n=============================================\n");
}

void searchP(struct department depts[], int deptCount){
    int pid, found=0;
    printf("\nEnter the Patient ID:");
    scanf("%d", &pid);
    for (int i = 0; i < deptCount; i++) {
        for (int j = 0; j < depts[i].currentPatientCount; j++) {
            if (depts[i].patients[j].p_id == pid) {
                found = 1;

                printf("\n=============================================\n");
                printf("               PATIENT FOUND                 \n");
                printf("=============================================\n");
                printf("Department     : %s (ID: %d)\n", depts[i].d_name, depts[i].d_id);
                printf("Patient ID     : %d\n", depts[i].patients[j].p_id);
                printf("Patient Name   : %s\n", depts[i].patients[j].p_name);
                printf("Age / Gender   : %d / %s\n", depts[i].patients[j].p_age, depts[i].patients[j].gender);
                printf("Contact Number : %s\n", depts[i].patients[j].contactNumber);
                printf("Disease        : %s\n", depts[i].patients[j].disease);
                printf("Admission Status: %s\n", depts[i].patients[j].admissionStatus);
                printf("=============================================\n");

                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        printf("\nError: Patient with ID %d not found in the system.\n", pid);
    }
}

void displayAdmittedInDept(struct department depts[], int deptCount) {
    int targetDeptId;
    int deptFound = 0;
    int admittedCount = 0;

    printf("\nEnter Department ID to view admitted patients: ");
    scanf("%d", &targetDeptId);

    for (int i = 0; i < deptCount; i++) {
        if (depts[i].d_id == targetDeptId) {
            deptFound = 1;
            printf("\n--- Admitted Patients in %s Department ---\n", depts[i].d_name);
            printf("%-6s | %-20s | %-4s | %-15s\n", "ID", "Name", "Age", "Disease");
            printf("---------------------------------------------------------\n");

            for (int j = 0; j < depts[i].currentPatientCount; j++) {
                // Using strcasecmp for case-insensitive comparison (or strcmp if strict)
                if (strcasecmp(depts[i].patients[j].admissionStatus, "Admitted") == 0) {
                    printf("%-6d | %-20s | %-4d | %-15s\n",
                           depts[i].patients[j].p_id,
                           depts[i].patients[j].p_name,
                           depts[i].patients[j].p_age,
                           depts[i].patients[j].disease);
                    admittedCount++;
                }
            }
            if (admittedCount == 0) {
                printf("No currently admitted patients in this department.\n");
            }
            break;
        }
    }

    if (!deptFound) {
        printf("Error: Department ID %d not found.\n", targetDeptId);
    }
}

void findOldestPatient(struct department depts[], int deptCount) {
    int maxAge = -1;
    int oldestDeptIndex = -1;
    int oldestPatientIndex = -1;

    for (int i = 0; i < deptCount; i++) {
        for (int j = 0; j < depts[i].currentPatientCount; j++) {
            if (depts[i].patients[j].p_age > maxAge) {
                maxAge = depts[i].patients[j].p_age;
                oldestDeptIndex = i;
                oldestPatientIndex = j;
            }
        }
    }

    if (oldestPatientIndex != -1) {
        struct patient p = depts[oldestDeptIndex].patients[oldestPatientIndex];
        printf("\n=============================================\n");
        printf("           OLDEST PATIENT RECORD             \n");
        printf("=============================================\n");
        printf("Name         : %s\n", p.p_name);
        printf("Age          : %d\n", p.p_age);
        printf("Department   : %s\n", depts[oldestDeptIndex].d_name);
        printf("Disease      : %s\n", p.disease);
        printf("Status       : %s\n", p.admissionStatus);
        printf("=============================================\n");
    } else {
        printf("\nNo patient records available to evaluate.\n");
    }
}

void countTotalAdmittedPatients(struct department depts[], int deptCount) {
    int totalAdmitted = 0;

    for (int i = 0; i < deptCount; i++) {
        for (int j = 0; j < depts[i].currentPatientCount; j++) {
            if (strcasecmp(depts[i].patients[j].admissionStatus, "Admitted") == 0) {
                totalAdmitted++;
            }
        }
    }

    printf("\n[Hospital Summary] Total Admitted Patients: %d\n", totalAdmitted);
}

int main() {
    struct department hospitalDepts[3];
    int numDepts = 3;
    int numPatients = 10;
    int choice;
    do {
        printf("\n=== HOSPITAL MANAGEMENT MENU ===\n");
        printf("1. Enter details of all departments and patients.\n");
        printf("2. Display the complete details of all departments.\n");
        printf("3. Search a patient using Patient ID. \n");
        printf("4. Display all patients admitted in a particular department.\n");
        printf("5. Find the oldest patient in the hospital. \n");
        printf("6. Count the number of admitted patients.  \n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getData(hospitalDepts, numDepts, numPatients);
                break;
            case 2:
                dispData(hospitalDepts, numDepts);
                break;
            case 3:
                searchP(hospitalDepts, numDepts);
                break;
            case 4:
                displayAdmittedInDept(hospitalDepts, numDepts);
                break;
            case 5:
                findOldestPatient(hospitalDepts, numDepts);
                break;
            case 6:
                countTotalAdmittedPatients(hospitalDepts, numDepts);
                break;
            case 7:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
                break;
        }
    }while (choice != 7);

    return 0;
}
