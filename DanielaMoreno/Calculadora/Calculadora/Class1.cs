using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculadora
{
    class Numero
    {
        private double numero;

        public void SetNumero(double numero)
        {
            this.numero = numero;
        }

        public double GetNumero()
        {
            return this.numero;
        }

        private static double ValidarNumero(string numero)
        {
            double retorno;
            if (!double.TryParse(numero,out retorno))
            {
                retorno = 0;
            }
                
            return retorno;
        }

        public Numero (double numero)
        {
            this.numero = numero;
        }

        public Numero (string numero)
        {
            this.numero = Numero.ValidarNumero(numero);
        }

        public static double SumarNumeros (Numero n1, Numero n2)
        {
            double retorno;
            retorno = n1.GetNumero() + n1.GetNumero();
            return retorno;
        }
    }
}
