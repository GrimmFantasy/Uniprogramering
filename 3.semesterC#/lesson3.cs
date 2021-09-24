using System;
using System.Collections;
using System.Collections.Generic;

namespace KG3{
    class Program
    {
        public static void Main(string[] args)
        {
            List<Car> cars = new List<Car>() 
            { 
                new Car(){Make="Skoda", Model = "Fabia", Price = 50000}, 
                new Car(){Make="Skoda", Model = "Octavia", Price = 60000},
                new Car(){Make="Ford", Model = "Tech", Price = 64300},
                new Car(){Make="Ford", Model = "Focus", Price = 72300},
                new Car(){Make="Kia", Model = "Soul", Price = 2000},
                new Car(){Make="Nissan", Model = "PP", Price = 69000} 
            };
            
            cars.Sort(new Car());
            
            foreach (Car l in cars)
            {
                Console.WriteLine(l.Make + " " +l.Model+ " " + l.Price);
            }
            
            Console.WriteLine("Done");
        }
    }
    class Car : IComparer<Car>//, IComparable<Car>
    { 
        public Car()
        {
            Make = Make;
            Model = Model;
            Price = Price;
        }
        
        public int Compare(Car other, Car here){
            
            int val = here.Make.CompareTo(other.Make);
             
            if(val == 0){
                val = here.Model.CompareTo(other.Model);
            }
            if(val == 0){
                return here.Price.CompareTo(other.Price);
            }
            
            return val;
            
             
        }
        public string Make { get; set; } 
        public string Model { get; set; } 
        public double Price { get; set; } 
        
    //    int CompareTo(Car other)
    //     {
    //         if(Price < other.Price)
    //         {
    //             return 1;
    //         }
    //         if(Price > other.Price)
    //         {
    //             return -1;
    //         }
    //         else
    //         {
    //             return 0;
    //         }
    //     }
    }
    
}