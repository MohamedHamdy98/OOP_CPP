#include <iostream>
using namespace std;

class Employee
{
    protected:
        string name;
        int emp_id;
        double salary;
    public:
        Employee(){}
        Employee(string name, int emp_id, double salary):name(name), emp_id(emp_id), salary(salary){}
        virtual float get_TotalSalary() = 0; // pure virtual function for abstract function
        virtual void print()
        {
            cout<<"\n"<<"name: "<< name<< "\n" << "emp_id: "<< emp_id << "\n"<< "salary: "<< salary<< "\n";
        }
};
class Sales: public Employee {
    protected:
        float goss_sales;
        float commission_rate;
    public:
        Sales(string name, int emp_id, double salary, float goss_sales,
         float commission_rate): Employee(name,emp_id,salary), goss_sales(goss_sales), commission_rate(commission_rate){}
        void set_goss_sales(float g_sales){goss_sales = g_sales;}
        void set_commission_rate(float c_rate){commission_rate = c_rate;}
        float get_TotalSalary()
        {
            return salary + (goss_sales * commission_rate);
        }
        void print()
        {
            Employee::print();
            cout<<"goss_sales: "<< goss_sales<< "\n" << "commission_rate: "<< commission_rate<<"\n";
        }
};

class Engineer: public Employee {
    protected:
        string specialty;
        int experince;
        int overtime_hours;
        float overtime_hours_rate;
    public:
        Engineer(string name, int emp_id, double salary, string specialty, 
            int experince, int overtime_hours, 
            float overtime_hours_rate):Employee(name,emp_id,salary), experince(experince),
            overtime_hours(overtime_hours), overtime_hours_rate(overtime_hours_rate){this->specialty=specialty;}
        void set_overtime_hours(int overtime_h){overtime_hours = overtime_h;}
        void set_overtime_hours_rate(float overtime_h_r){overtime_hours_rate = overtime_h_r;}
        float get_TotalSalary()
        {
            return salary + (overtime_hours * overtime_hours_rate);
        }
        void print()
        {
            Employee::print();
            cout<<"specialty: "<< specialty<< "\n" << "experince: "<< experince<< "\n" 
                << "overtime_hours: "<< overtime_hours<< "\n" << "overtime_hours_rate: "<< overtime_hours_rate;
        }
};

int main()
{
    Employee* ptr;
    
    Sales sales("Mohammed", 1, 15000, 2000, 0.1);
    ptr = &sales;
    ptr->print();
    cout <<"TotalSalary of Sales Emp: " << ptr->get_TotalSalary()<<"\n";

    Engineer eng("Ahmed", 2, 20000, "Teacher", 6, 240, 0);
    ptr = &eng;
    ptr->print();
    cout <<"\n"<<"TotalSalary of Engineer Emp: "<< ptr->get_TotalSalary();
    return 0; 
}