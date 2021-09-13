using System;
using System.Collections.Generic;
public class Student
            {
                string Name {get; set;}
                public Student(string name)
                {
                    Name = name;
                }
                public override string ToString()
                {
                    return Name;
                }
            }

namespace KG1{
         class Program{
           

        static void Main(string[] args){
            List<Student> Gruop = new List<Student>();
            
            int j = 10;
            Console.WriteLine(j);

            for (int i = 0; i < j; i++)
            {
                for (int u = 0; u < i; u++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }

            for (int i = 0; i < j; i++)
            {
                for (int u = j; u > i+1; u--)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
            string input = Console.ReadLine(); 
            int tal = int.Parse(input);
            Console.WriteLine(Math.Sqrt(tal));

            Boolean fact = false;
            while (fact != true)
            {
                input = Console.ReadLine(); 
                if (input == "s")
                {
                    fact = true;
                }else{
                    var name = new Student(input);
                    Gruop.Add(name);
                }
            }
            foreach (Student item in Gruop)
            {
                Console.WriteLine(item);
            }

        }

    }
}