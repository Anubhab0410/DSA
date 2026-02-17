#include <stdio.h>
typedef struct {
    int emp_id;
    char name[100];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
} Employee;

float calculateGrossSalary(Employee emp) {
    float hra = (emp.hra_percent / 100) * emp.basic_salary;
    float da = (emp.da_percent / 100) * emp.basic_salary;
    return emp.basic_salary + hra + da;
}

void inputEmployeeDetails(Employee *emp) {
    printf("Enter employee ID: ");
    scanf("%d", &emp->emp_id);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", emp->name); 
    printf("Enter designation: ");
    scanf(" %[^\n]%*c", emp->designation); 
    printf("Enter basic salary: ");
    scanf("%f", &emp->basic_salary);
    printf("Enter HRA percentage: ");
    scanf("%f", &emp->hra_percent);
    printf("Enter DA percentage: ");
    scanf("%f", &emp->da_percent);
}

void displayEmployeeDetails(Employee emp) {
    float gross_salary = calculateGrossSalary(emp);
    printf("\nEmployee ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Basic Salary: %.2f\n", emp.basic_salary);
    printf("HRA Percentage: %.2f%%\n", emp.hra_percent);
    printf("DA Percentage: %.2f%%\n", emp.da_percent);
    printf("Gross Salary: %.2f\n", gross_salary);
}

int main() {
    int n;


    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee employees[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        inputEmployeeDetails(&employees[i]);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        displayEmployeeDetails(employees[i]);
    }

    return 0;
}
