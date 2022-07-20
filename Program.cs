using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;

namespace InensiaTask
{
    public class MovieStar
    {
        public string dateOfBirth { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Sex { get; set; }
        public string Nationality { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader r = new StreamReader("D:\\Laptop\\Inensia\\input.txt"))
            {
                string json = r.ReadToEnd();
                List<MovieStar> stars = JsonConvert.DeserializeObject<List<MovieStar>>(json);

                foreach (MovieStar s in stars)
                {
                    int year = int.Parse(s.dateOfBirth.Split(", ")[1]);
                    Console.WriteLine("{0} {1}\n{2}\n{3}\n{4} years old\n", 
                                       s.Name, s.Surname, s.Sex, s.Nationality, 2022 - year);
                }
            }
        }
    }
}
