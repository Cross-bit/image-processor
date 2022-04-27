# Software pro úpravu obrázků a generátor ASCII art, Ondřej Kříž
## Stručný popis:

Aplikace bude uživateli nabízet jednoduché konzolové rozhranní umožňující základní editaci obrázků. Především se bude jednat o vybrané filtry a konvulence jmenované níže, základní transformace obrázku a generování ASCII art.  

## Vlastnosti:
Podporované filtry/úpravy:
 - změna kontrastu
 - změna jasu
 - saturace barev (tedy i převod na grayscale)
 - vyvolání negativu
 - blur/gaussovský blur

Export do ASCII art
(Případně možná umožním uživateli libovolnou volbu mapy ASCII znaků, na základě níž se budou jednotlivé pixely nahrazovat.)


Dále bych chtěl do aplikace přidat základní transformační operace, jako například:
- otočení obrazu o násobky 90 ° (případně bych mohl přidat rozšíření rotace i o libovolný úhel)
- překlopení po horizontální, či vertikální ose

## Práce v softwaru
Samotný interface se ještě možná bude lehce lišit, nicméně v momentální chvíli by práce mohla vypadat například následovně:
 1. Na začátku se uživateli zobrazí hlavní rozcestník s položkami:
  - Load image; - umožní nahrát obrázky do aplikace (na základě např. absolutní cesty)
  - Choose edit operation; - Zvolení příslušné operace (možná rozdělím na 3 samostatné položky filtry, transformace, ASCII art)
  - Exit;
 2. Poté co uživatel nahraje obrázky do aplikace, přejde do nabídky volby operace.
 3. V nastevení operace uživatel zvolí vstupní obrázek a navolí vstupní parametry daného filtru - tedy např. s jakou intenzitou se bude aplikovat.(Přičemž v rozhraní budou uvedeny doporučené hodnoty a (horní a dolní meze) pro každý filtr.)
 4. Po provedení zvolené operace je uživatel přesměrován zpět na hlavní rozcestník.
 
## Rozhraní aplikace:
Rozhranní zvolím buď čistě textového charakteru, nebo bych případně mohl využít knihovnu ncurses. 

## Vstup & Výstup
Chtěl bych aby aplikace podporovala alespoň dva rozličné formáty obrázků (nejspíše zvolím .jpg a .tga), přičemž k jejich zpracování použiji specifické knihovny.

Výstupem aplikace poté bude v případě ASCII art tisk převedeného obrázku do konzole (případně bych mohl přidat export do textového souboru). V případě operací filtrů a transformací obrázku, se nový obrázek exportuje do předdefinovaného adresáře s předdefinovaným novým názvem(pravděpodobně tvořeným názvem původního obrázku s suffixem odpovídajícím konkrétní editační operaci). Formát výstupu nechám nejspíše stejný jako měl vstupní soubor, nebo nechám volbu na uživateli.


## Příklad výsledného ASCII art:
<img src="zapoctovy_program_specifikace/ascii_example.jpg" alt="drawing" width="400"/> <br>
Pro vytvoření jsem použil: https://manytools.org/hacker-tools/convert-images-to-ascii-art/

Případně další příklady <a href="https://www.google.cz/search?q=ascii+art&sxsrf=AOaemvIimboiElMdk7LrD4VW4hkXoNpNoQ:1637189735808&source=lnms&tbm=isch&sa=X&ved=2ahUKEwjFuYeFv6D0AhWC-6QKHQMoAokQ_AUoAXoECAIQAw&biw=1920&bih=937&dpr=1">zde</a>.

## Příklady výsledných filtrů:
Na obrázku níže jsou uvedeny vzorové výstupy jednotlivých filtrů seřazené tak, jak jsou vyjmenovány výše v seznamu.
Samozřejmě výsledný vzhled se bude případně lišit dle konkrétních nastavením daného filtru.<br>
<img src="zapoctovy_program_specifikace/penguin_filters.jpg" alt="drawing" width="400"/> <br>


## Rozšíření & Poznámky
Dalším možné rozšíření, které bych mohl případně do aplikace přidat(však negarantuji, že skutečně stihnu) by mohla být tvorby krátkých ASCII art animací, z několika obrázků. Případně konverze do video formátů.
Příklad takového rozšíření: https://www.youtube.com/watch?v=hLLbFx9r62U

Případně přidám další filtry, založené na kovulenčním jádře, např.:
 - efekt emboss
 - zostření
 - outline

Jako příklad konvulencí zde uvádím odkaz na krátký článek ve stručnosti popisující problematiku konvulenčíního jádra(image kernel) s live editorem <a href="https://setosa.io/ev/image-kernels/">zde</a>. A případně odkaz na článek wikipedie <a href="https://en.wikipedia.org/wiki/Kernel_(image_processing)">zde</a>.

Výsledek bych nejraději postupně přidával <a href ="https://github.com/Cross-bit/image_processor.git">zde</a> do svého veřejného repozitáře na githubu. Pokud by bylo však nutné používat tento repozitář(či jiný na mff gitlabu) tak se samozřejmě přizpůsobím.
