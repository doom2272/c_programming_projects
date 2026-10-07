#include <stdio.h>

#define NUM_CODES \
  ((int) (sizeof(country_codes) / sizeof(country_codes[0])))

struct dialing_code {
  char *country;
  int code;
};

const struct dialing_code country_codes[] = {
  {"Argentina",             54}, {"Bangladesh",       880},
  {"Brasil",                55}, {"Burma (Myanmar)",   95},
  {"China",                 86}, {"Colombia",          57},
  {"Congo, Dem. Rep. Of",  243}, {"Egypt",             20},
  {"Ethiopia",             251}, {"France",            33},
  {"Germany",               49}, {"India",             91},
  {"Indonesia",             62}, {"Iran",              98},
  {"Italy",                 39}, {"Japan",             81},
  {"Mexico",                52}, {"Nigeria",          234},
  {"Pakistan",              92}, {"Philippines",       63},
  {"Poland",                48}, {"Russia",             7},
  {"South Africa",          27}, {"South Korea",       82},
  {"Spain",                 34}, {"Sudan",            249},
  {"Thailand",              66}, {"Turkey",            90},
  {"Ukraine",              380}, {"United Kingdom",    44},
  {"United States",          1}, {"Vietnam",           84}
};

int main(void)
{

  int cod, i;

  printf("Enter international dialing code: ");
  scanf("%d", &cod);

  for ( i = 0; i < NUM_CODES; i++){
    if (cod == country_codes[i].code) {
      printf("The country with the dialing code %d is %s\n", cod, country_codes[i].country);
      return 0;
    }
  }
  printf("No corresponding country found for the dialing code %d !!\n", cod);

  return 0;
}
