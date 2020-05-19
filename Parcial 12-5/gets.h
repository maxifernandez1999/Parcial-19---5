

/** \brief pide un numero entero al usuario y lo valida entre un maximo y un minimo
 *
 * \param message[] char recibe un mensaje de lo que desea ingresar
 * \param errorMessage[] char recibe en mensaje de error si el numero no es valido
 * \param int recibe un minimo
 * \param int recibe un maximo
 * \return int retorna el numero ingresado mientras este entre el maximo y el minimo
 *
 */
int getInt(char message[], char errorMessage[], int , int );

/** \brief pide un numero decimal al usuario y lo valida entre un maximo y un minimo
 *
 * \param message[] char recibe un mensaje de lo que desea ingresar
 * \param errorMessage[] char recibe en mensaje de error si el numero no es valido
 * \param mn int recibe un minimo
 * \param int recibe un maximo
 * \return float retorna el numero ingresado mientras este entre el maximo y el minimo
 *
 */
float getFloat(char message[], char errorMessage[], int , int );

/** \brief pide un caracter al usuario y lo valida entre un maximo y un minimo
 *
 * \param message[] char recibe un mensaje de lo que desea ingresar
 * \param errorMessage[] char recibe en mensaje de error si el caracter no es valido
 * \param char recibe un minimo
 * \param char recibe un maximo
 * \return char retorna el caracter ingresado mientras este entre el maximo y el minimo
 *
 */
char getCharacter(char message[], char errorMessage[], char , char );

/** \brief  pide un una cadena de caracteres al usuario
 *
 * \param mensaje[] char recibe un mensaje de lo que desea ingresar
 * \param [] char recibe la cadena de caracteres
 * \return void
 *
 */
void getString(char mensaje[], char []);
