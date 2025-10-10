using System;

namespace test2
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> feipolaci = new List<int> { 1, 1 };

            int i = 3;      
            while (i <= 20)
            {
                feipolaci.Add(feipolaci[feipolaci.Count - 1]  + feipolaci[feipolaci.Count - 2]);
                ++i;
            }
            Console.WriteLine(feipolaci[i-2]);
        }
    }
}