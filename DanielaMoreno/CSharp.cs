using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace ParcialOrquesta
{
  class Program
  {
    static void Main(string[] args)
    {
      Orquesta orquesta1 = new Orquesta();
      //orquesta1.ImprimirOrquesta();
      Orquesta orquesta2 = new Orquesta("Orquesta2", "lugarS", "sinfonica");
      //orquesta2.ImprimirOrquesta();

      Instrumento instrumento1 = new Instrumento();
      instrumento1.ImprimirInstrumento();
      Instrumento instrumento2 = new Instrumento("Violin", "Cuerda");
      instrumento2.ImprimirInstrumento();

      Musico musico1 = new Musico("Pepe", "Fafa", 23, orquesta2, instrumento2);
      musico1.ImprimirMusico();

      ArrayList listaOrquesta = new ArrayList();
      listaOrquesta.Add(orquesta1);
      listaOrquesta.Add(orquesta2);

      foreach(Orquesta elemento in listaOrquesta)
      {
        elemento.ImprimirOrquesta();

      }
    }
  }
}
