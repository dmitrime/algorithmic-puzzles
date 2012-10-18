#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

typedef long long int LL;

const int MX_LEN = 19;
const int MX_SUM = 164;
const int MX_SQSUM = 1460;
LL dp[MX_LEN][MX_SUM][MX_SQSUM]; // len - digit sum - square digit sum
LL tempo[MX_LEN][10][MX_SUM][MX_SQSUM];
short sqvalues[MX_LEN][MX_SUM][MX_SQSUM];
int primes[1460];

void precompute()
{
    primes[0]=0; primes[1]=0; primes[2]=1; primes[3]=1; primes[4]=0; primes[5]=1; primes[6]=0; primes[7]=1; primes[8]=0; primes[9]=0; primes[10]=0; primes[11]=1; primes[12]=0; primes[13]=1; primes[14]=0; primes[15]=0; primes[16]=0; primes[17]=1; primes[18]=0; primes[19]=1; primes[20]=0; primes[21]=0; primes[22]=0; primes[23]=1; primes[24]=0; primes[25]=0; primes[26]=0; primes[27]=0; primes[28]=0; primes[29]=1; primes[30]=0; primes[31]=1; primes[32]=0; primes[33]=0; primes[34]=0; primes[35]=0; primes[36]=0; primes[37]=1; primes[38]=0; primes[39]=0; primes[40]=0; primes[41]=1; primes[42]=0; primes[43]=1; primes[44]=0; primes[45]=0; primes[46]=0; primes[47]=1; primes[48]=0; primes[49]=0; primes[50]=0; primes[51]=0; primes[52]=0; primes[53]=1; primes[54]=0; primes[55]=0; primes[56]=0; primes[57]=0; primes[58]=0; primes[59]=1; primes[60]=0; primes[61]=1; primes[62]=0; primes[63]=0; primes[64]=0; primes[65]=0; primes[66]=0; primes[67]=1; primes[68]=0; primes[69]=0; primes[70]=0; primes[71]=1; primes[72]=0; primes[73]=1; primes[74]=0; primes[75]=0; primes[76]=0; primes[77]=0; primes[78]=0; primes[79]=1; primes[80]=0; primes[81]=0; primes[82]=0; primes[83]=1; primes[84]=0; primes[85]=0; primes[86]=0; primes[87]=0; primes[88]=0; primes[89]=1; primes[90]=0; primes[91]=0; primes[92]=0; primes[93]=0; primes[94]=0; primes[95]=0; primes[96]=0; primes[97]=1; primes[98]=0; primes[99]=0; primes[100]=0; primes[101]=1; primes[102]=0; primes[103]=1; primes[104]=0; primes[105]=0; primes[106]=0; primes[107]=1; primes[108]=0; primes[109]=1; primes[110]=0; primes[111]=0; primes[112]=0; primes[113]=1; primes[114]=0; primes[115]=0; primes[116]=0; primes[117]=0; primes[118]=0; primes[119]=0;
    primes[120]=0; primes[121]=0; primes[122]=0; primes[123]=0; primes[124]=0; primes[125]=0; primes[126]=0; primes[127]=1; primes[128]=0; primes[129]=0; primes[130]=0; primes[131]=1; primes[132]=0; primes[133]=0; primes[134]=0; primes[135]=0; primes[136]=0; primes[137]=1; primes[138]=0; primes[139]=1; primes[140]=0; primes[141]=0; primes[142]=0; primes[143]=0; primes[144]=0; primes[145]=0; primes[146]=0; primes[147]=0; primes[148]=0; primes[149]=1; primes[150]=0; primes[151]=1; primes[152]=0; primes[153]=0; primes[154]=0; primes[155]=0; primes[156]=0; primes[157]=1; primes[158]=0; primes[159]=0; primes[160]=0; primes[161]=0; primes[162]=0; primes[163]=1; primes[164]=0; primes[165]=0; primes[166]=0; primes[167]=1; primes[168]=0; primes[169]=0; primes[170]=0; primes[171]=0; primes[172]=0; primes[173]=1; primes[174]=0; primes[175]=0; primes[176]=0; primes[177]=0; primes[178]=0; primes[179]=1; primes[180]=0; primes[181]=1; primes[182]=0; primes[183]=0; primes[184]=0; primes[185]=0; primes[186]=0; primes[187]=0; primes[188]=0; primes[189]=0; primes[190]=0; primes[191]=1; primes[192]=0; primes[193]=1; primes[194]=0; primes[195]=0; primes[196]=0; primes[197]=1; primes[198]=0; primes[199]=1; primes[200]=0; primes[201]=0; primes[202]=0; primes[203]=0; primes[204]=0; primes[205]=0; primes[206]=0; primes[207]=0; primes[208]=0; primes[209]=0; primes[210]=0; primes[211]=1; primes[212]=0; primes[213]=0; primes[214]=0; primes[215]=0; primes[216]=0; primes[217]=0; primes[218]=0; primes[219]=0; primes[220]=0; primes[221]=0; primes[222]=0; primes[223]=1; primes[224]=0; primes[225]=0; primes[226]=0; primes[227]=1; primes[228]=0; primes[229]=1; primes[230]=0; primes[231]=0; primes[232]=0; primes[233]=1; primes[234]=0; primes[235]=0; primes[236]=0; primes[237]=0; primes[238]=0; primes[239]=1;
    primes[240]=0; primes[241]=1; primes[242]=0; primes[243]=0; primes[244]=0; primes[245]=0; primes[246]=0; primes[247]=0; primes[248]=0; primes[249]=0; primes[250]=0; primes[251]=1; primes[252]=0; primes[253]=0; primes[254]=0; primes[255]=0; primes[256]=0; primes[257]=1; primes[258]=0; primes[259]=0; primes[260]=0; primes[261]=0; primes[262]=0; primes[263]=1; primes[264]=0; primes[265]=0; primes[266]=0; primes[267]=0; primes[268]=0; primes[269]=1; primes[270]=0; primes[271]=1; primes[272]=0; primes[273]=0; primes[274]=0; primes[275]=0; primes[276]=0; primes[277]=1; primes[278]=0; primes[279]=0; primes[280]=0; primes[281]=1; primes[282]=0; primes[283]=1; primes[284]=0; primes[285]=0; primes[286]=0; primes[287]=0; primes[288]=0; primes[289]=0; primes[290]=0; primes[291]=0; primes[292]=0; primes[293]=1; primes[294]=0; primes[295]=0; primes[296]=0; primes[297]=0; primes[298]=0; primes[299]=0; primes[300]=0; primes[301]=0; primes[302]=0; primes[303]=0; primes[304]=0; primes[305]=0; primes[306]=0; primes[307]=1; primes[308]=0; primes[309]=0; primes[310]=0; primes[311]=1; primes[312]=0; primes[313]=1; primes[314]=0; primes[315]=0; primes[316]=0; primes[317]=1; primes[318]=0; primes[319]=0; primes[320]=0; primes[321]=0; primes[322]=0; primes[323]=0; primes[324]=0; primes[325]=0; primes[326]=0; primes[327]=0; primes[328]=0; primes[329]=0; primes[330]=0; primes[331]=1; primes[332]=0; primes[333]=0; primes[334]=0; primes[335]=0; primes[336]=0; primes[337]=1; primes[338]=0; primes[339]=0; primes[340]=0; primes[341]=0; primes[342]=0; primes[343]=0; primes[344]=0; primes[345]=0; primes[346]=0; primes[347]=1; primes[348]=0; primes[349]=1; primes[350]=0; primes[351]=0; primes[352]=0; primes[353]=1; primes[354]=0; primes[355]=0; primes[356]=0; primes[357]=0; primes[358]=0; primes[359]=1;
    primes[360]=0; primes[361]=0; primes[362]=0; primes[363]=0; primes[364]=0; primes[365]=0; primes[366]=0; primes[367]=1; primes[368]=0; primes[369]=0; primes[370]=0; primes[371]=0; primes[372]=0; primes[373]=1; primes[374]=0; primes[375]=0; primes[376]=0; primes[377]=0; primes[378]=0; primes[379]=1; primes[380]=0; primes[381]=0; primes[382]=0; primes[383]=1; primes[384]=0; primes[385]=0; primes[386]=0; primes[387]=0; primes[388]=0; primes[389]=1; primes[390]=0; primes[391]=0; primes[392]=0; primes[393]=0; primes[394]=0; primes[395]=0; primes[396]=0; primes[397]=1; primes[398]=0; primes[399]=0; primes[400]=0; primes[401]=1; primes[402]=0; primes[403]=0; primes[404]=0; primes[405]=0; primes[406]=0; primes[407]=0; primes[408]=0; primes[409]=1; primes[410]=0; primes[411]=0; primes[412]=0; primes[413]=0; primes[414]=0; primes[415]=0; primes[416]=0; primes[417]=0; primes[418]=0; primes[419]=1; primes[420]=0; primes[421]=1; primes[422]=0; primes[423]=0; primes[424]=0; primes[425]=0; primes[426]=0; primes[427]=0; primes[428]=0; primes[429]=0; primes[430]=0; primes[431]=1; primes[432]=0; primes[433]=1; primes[434]=0; primes[435]=0; primes[436]=0; primes[437]=0; primes[438]=0; primes[439]=1; primes[440]=0; primes[441]=0; primes[442]=0; primes[443]=1; primes[444]=0; primes[445]=0; primes[446]=0; primes[447]=0; primes[448]=0; primes[449]=1; primes[450]=0; primes[451]=0; primes[452]=0; primes[453]=0; primes[454]=0; primes[455]=0; primes[456]=0; primes[457]=1; primes[458]=0; primes[459]=0; primes[460]=0; primes[461]=1; primes[462]=0; primes[463]=1; primes[464]=0; primes[465]=0; primes[466]=0; primes[467]=1; primes[468]=0; primes[469]=0; primes[470]=0; primes[471]=0; primes[472]=0; primes[473]=0; primes[474]=0; primes[475]=0; primes[476]=0; primes[477]=0; primes[478]=0; primes[479]=1;
    primes[480]=0; primes[481]=0; primes[482]=0; primes[483]=0; primes[484]=0; primes[485]=0; primes[486]=0; primes[487]=1; primes[488]=0; primes[489]=0; primes[490]=0; primes[491]=1; primes[492]=0; primes[493]=0; primes[494]=0; primes[495]=0; primes[496]=0; primes[497]=0; primes[498]=0; primes[499]=1; primes[500]=0; primes[501]=0; primes[502]=0; primes[503]=1; primes[504]=0; primes[505]=0; primes[506]=0; primes[507]=0; primes[508]=0; primes[509]=1; primes[510]=0; primes[511]=0; primes[512]=0; primes[513]=0; primes[514]=0; primes[515]=0; primes[516]=0; primes[517]=0; primes[518]=0; primes[519]=0; primes[520]=0; primes[521]=1; primes[522]=0; primes[523]=1; primes[524]=0; primes[525]=0; primes[526]=0; primes[527]=0; primes[528]=0; primes[529]=0; primes[530]=0; primes[531]=0; primes[532]=0; primes[533]=0; primes[534]=0; primes[535]=0; primes[536]=0; primes[537]=0; primes[538]=0; primes[539]=0; primes[540]=0; primes[541]=1; primes[542]=0; primes[543]=0; primes[544]=0; primes[545]=0; primes[546]=0; primes[547]=1; primes[548]=0; primes[549]=0; primes[550]=0; primes[551]=0; primes[552]=0; primes[553]=0; primes[554]=0; primes[555]=0; primes[556]=0; primes[557]=1; primes[558]=0; primes[559]=0; primes[560]=0; primes[561]=0; primes[562]=0; primes[563]=1; primes[564]=0; primes[565]=0; primes[566]=0; primes[567]=0; primes[568]=0; primes[569]=1; primes[570]=0; primes[571]=1; primes[572]=0; primes[573]=0; primes[574]=0; primes[575]=0; primes[576]=0; primes[577]=1; primes[578]=0; primes[579]=0; primes[580]=0; primes[581]=0; primes[582]=0; primes[583]=0; primes[584]=0; primes[585]=0; primes[586]=0; primes[587]=1; primes[588]=0; primes[589]=0; primes[590]=0; primes[591]=0; primes[592]=0; primes[593]=1; primes[594]=0; primes[595]=0; primes[596]=0; primes[597]=0; primes[598]=0; primes[599]=1;
    primes[600]=0; primes[601]=1; primes[602]=0; primes[603]=0; primes[604]=0; primes[605]=0; primes[606]=0; primes[607]=1; primes[608]=0; primes[609]=0; primes[610]=0; primes[611]=0; primes[612]=0; primes[613]=1; primes[614]=0; primes[615]=0; primes[616]=0; primes[617]=1; primes[618]=0; primes[619]=1; primes[620]=0; primes[621]=0; primes[622]=0; primes[623]=0; primes[624]=0; primes[625]=0; primes[626]=0; primes[627]=0; primes[628]=0; primes[629]=0; primes[630]=0; primes[631]=1; primes[632]=0; primes[633]=0; primes[634]=0; primes[635]=0; primes[636]=0; primes[637]=0; primes[638]=0; primes[639]=0; primes[640]=0; primes[641]=1; primes[642]=0; primes[643]=1; primes[644]=0; primes[645]=0; primes[646]=0; primes[647]=1; primes[648]=0; primes[649]=0; primes[650]=0; primes[651]=0; primes[652]=0; primes[653]=1; primes[654]=0; primes[655]=0; primes[656]=0; primes[657]=0; primes[658]=0; primes[659]=1; primes[660]=0; primes[661]=1; primes[662]=0; primes[663]=0; primes[664]=0; primes[665]=0; primes[666]=0; primes[667]=0; primes[668]=0; primes[669]=0; primes[670]=0; primes[671]=0; primes[672]=0; primes[673]=1; primes[674]=0; primes[675]=0; primes[676]=0; primes[677]=1; primes[678]=0; primes[679]=0; primes[680]=0; primes[681]=0; primes[682]=0; primes[683]=1; primes[684]=0; primes[685]=0; primes[686]=0; primes[687]=0; primes[688]=0; primes[689]=0; primes[690]=0; primes[691]=1; primes[692]=0; primes[693]=0; primes[694]=0; primes[695]=0; primes[696]=0; primes[697]=0; primes[698]=0; primes[699]=0; primes[700]=0; primes[701]=1; primes[702]=0; primes[703]=0; primes[704]=0; primes[705]=0; primes[706]=0; primes[707]=0; primes[708]=0; primes[709]=1; primes[710]=0; primes[711]=0; primes[712]=0; primes[713]=0; primes[714]=0; primes[715]=0; primes[716]=0; primes[717]=0; primes[718]=0; primes[719]=1;
    primes[720]=0; primes[721]=0; primes[722]=0; primes[723]=0; primes[724]=0; primes[725]=0; primes[726]=0; primes[727]=1; primes[728]=0; primes[729]=0; primes[730]=0; primes[731]=0; primes[732]=0; primes[733]=1; primes[734]=0; primes[735]=0; primes[736]=0; primes[737]=0; primes[738]=0; primes[739]=1; primes[740]=0; primes[741]=0; primes[742]=0; primes[743]=1; primes[744]=0; primes[745]=0; primes[746]=0; primes[747]=0; primes[748]=0; primes[749]=0; primes[750]=0; primes[751]=1; primes[752]=0; primes[753]=0; primes[754]=0; primes[755]=0; primes[756]=0; primes[757]=1; primes[758]=0; primes[759]=0; primes[760]=0; primes[761]=1; primes[762]=0; primes[763]=0; primes[764]=0; primes[765]=0; primes[766]=0; primes[767]=0; primes[768]=0; primes[769]=1; primes[770]=0; primes[771]=0; primes[772]=0; primes[773]=1; primes[774]=0; primes[775]=0; primes[776]=0; primes[777]=0; primes[778]=0; primes[779]=0; primes[780]=0; primes[781]=0; primes[782]=0; primes[783]=0; primes[784]=0; primes[785]=0; primes[786]=0; primes[787]=1; primes[788]=0; primes[789]=0; primes[790]=0; primes[791]=0; primes[792]=0; primes[793]=0; primes[794]=0; primes[795]=0; primes[796]=0; primes[797]=1; primes[798]=0; primes[799]=0; primes[800]=0; primes[801]=0; primes[802]=0; primes[803]=0; primes[804]=0; primes[805]=0; primes[806]=0; primes[807]=0; primes[808]=0; primes[809]=1; primes[810]=0; primes[811]=1; primes[812]=0; primes[813]=0; primes[814]=0; primes[815]=0; primes[816]=0; primes[817]=0; primes[818]=0; primes[819]=0; primes[820]=0; primes[821]=1; primes[822]=0; primes[823]=1; primes[824]=0; primes[825]=0; primes[826]=0; primes[827]=1; primes[828]=0; primes[829]=1; primes[830]=0; primes[831]=0; primes[832]=0; primes[833]=0; primes[834]=0; primes[835]=0; primes[836]=0; primes[837]=0; primes[838]=0; primes[839]=1;
    primes[840]=0; primes[841]=0; primes[842]=0; primes[843]=0; primes[844]=0; primes[845]=0; primes[846]=0; primes[847]=0; primes[848]=0; primes[849]=0; primes[850]=0; primes[851]=0; primes[852]=0; primes[853]=1; primes[854]=0; primes[855]=0; primes[856]=0; primes[857]=1; primes[858]=0; primes[859]=1; primes[860]=0; primes[861]=0; primes[862]=0; primes[863]=1; primes[864]=0; primes[865]=0; primes[866]=0; primes[867]=0; primes[868]=0; primes[869]=0; primes[870]=0; primes[871]=0; primes[872]=0; primes[873]=0; primes[874]=0; primes[875]=0; primes[876]=0; primes[877]=1; primes[878]=0; primes[879]=0; primes[880]=0; primes[881]=1; primes[882]=0; primes[883]=1; primes[884]=0; primes[885]=0; primes[886]=0; primes[887]=1; primes[888]=0; primes[889]=0; primes[890]=0; primes[891]=0; primes[892]=0; primes[893]=0; primes[894]=0; primes[895]=0; primes[896]=0; primes[897]=0; primes[898]=0; primes[899]=0; primes[900]=0; primes[901]=0; primes[902]=0; primes[903]=0; primes[904]=0; primes[905]=0; primes[906]=0; primes[907]=1; primes[908]=0; primes[909]=0; primes[910]=0; primes[911]=1; primes[912]=0; primes[913]=0; primes[914]=0; primes[915]=0; primes[916]=0; primes[917]=0; primes[918]=0; primes[919]=1; primes[920]=0; primes[921]=0; primes[922]=0; primes[923]=0; primes[924]=0; primes[925]=0; primes[926]=0; primes[927]=0; primes[928]=0; primes[929]=1; primes[930]=0; primes[931]=0; primes[932]=0; primes[933]=0; primes[934]=0; primes[935]=0; primes[936]=0; primes[937]=1; primes[938]=0; primes[939]=0; primes[940]=0; primes[941]=1; primes[942]=0; primes[943]=0; primes[944]=0; primes[945]=0; primes[946]=0; primes[947]=1; primes[948]=0; primes[949]=0; primes[950]=0; primes[951]=0; primes[952]=0; primes[953]=1; primes[954]=0; primes[955]=0; primes[956]=0; primes[957]=0; primes[958]=0; primes[959]=0;
    primes[960]=0; primes[961]=0; primes[962]=0; primes[963]=0; primes[964]=0; primes[965]=0; primes[966]=0; primes[967]=1; primes[968]=0; primes[969]=0; primes[970]=0; primes[971]=1; primes[972]=0; primes[973]=0; primes[974]=0; primes[975]=0; primes[976]=0; primes[977]=1; primes[978]=0; primes[979]=0; primes[980]=0; primes[981]=0; primes[982]=0; primes[983]=1; primes[984]=0; primes[985]=0; primes[986]=0; primes[987]=0; primes[988]=0; primes[989]=0; primes[990]=0; primes[991]=1; primes[992]=0; primes[993]=0; primes[994]=0; primes[995]=0; primes[996]=0; primes[997]=1; primes[998]=0; primes[999]=0; primes[1000]=0; primes[1001]=0; primes[1002]=0; primes[1003]=0; primes[1004]=0; primes[1005]=0; primes[1006]=0; primes[1007]=0; primes[1008]=0; primes[1009]=1; primes[1010]=0; primes[1011]=0; primes[1012]=0; primes[1013]=1; primes[1014]=0; primes[1015]=0; primes[1016]=0; primes[1017]=0; primes[1018]=0; primes[1019]=1; primes[1020]=0; primes[1021]=1; primes[1022]=0; primes[1023]=0; primes[1024]=0; primes[1025]=0; primes[1026]=0; primes[1027]=0; primes[1028]=0; primes[1029]=0; primes[1030]=0; primes[1031]=1; primes[1032]=0; primes[1033]=1; primes[1034]=0; primes[1035]=0; primes[1036]=0; primes[1037]=0; primes[1038]=0; primes[1039]=1; primes[1040]=0; primes[1041]=0; primes[1042]=0; primes[1043]=0; primes[1044]=0; primes[1045]=0; primes[1046]=0; primes[1047]=0; primes[1048]=0; primes[1049]=1; primes[1050]=0; primes[1051]=1; primes[1052]=0; primes[1053]=0; primes[1054]=0; primes[1055]=0; primes[1056]=0; primes[1057]=0; primes[1058]=0; primes[1059]=0; primes[1060]=0; primes[1061]=1; primes[1062]=0; primes[1063]=1; primes[1064]=0; primes[1065]=0; primes[1066]=0; primes[1067]=0; primes[1068]=0; primes[1069]=1; primes[1070]=0; primes[1071]=0; primes[1072]=0; primes[1073]=0; primes[1074]=0; primes[1075]=0; primes[1076]=0; primes[1077]=0; primes[1078]=0; primes[1079]=0;
    primes[1080]=0; primes[1081]=0; primes[1082]=0; primes[1083]=0; primes[1084]=0; primes[1085]=0; primes[1086]=0; primes[1087]=1; primes[1088]=0; primes[1089]=0; primes[1090]=0; primes[1091]=1; primes[1092]=0; primes[1093]=1; primes[1094]=0; primes[1095]=0; primes[1096]=0; primes[1097]=1; primes[1098]=0; primes[1099]=0; primes[1100]=0; primes[1101]=0; primes[1102]=0; primes[1103]=1; primes[1104]=0; primes[1105]=0; primes[1106]=0; primes[1107]=0; primes[1108]=0; primes[1109]=1; primes[1110]=0; primes[1111]=0; primes[1112]=0; primes[1113]=0; primes[1114]=0; primes[1115]=0; primes[1116]=0; primes[1117]=1; primes[1118]=0; primes[1119]=0; primes[1120]=0; primes[1121]=0; primes[1122]=0; primes[1123]=1; primes[1124]=0; primes[1125]=0; primes[1126]=0; primes[1127]=0; primes[1128]=0; primes[1129]=1; primes[1130]=0; primes[1131]=0; primes[1132]=0; primes[1133]=0; primes[1134]=0; primes[1135]=0; primes[1136]=0; primes[1137]=0; primes[1138]=0; primes[1139]=0; primes[1140]=0; primes[1141]=0; primes[1142]=0; primes[1143]=0; primes[1144]=0; primes[1145]=0; primes[1146]=0; primes[1147]=0; primes[1148]=0; primes[1149]=0; primes[1150]=0; primes[1151]=1; primes[1152]=0; primes[1153]=1; primes[1154]=0; primes[1155]=0; primes[1156]=0; primes[1157]=0; primes[1158]=0; primes[1159]=0; primes[1160]=0; primes[1161]=0; primes[1162]=0; primes[1163]=1; primes[1164]=0; primes[1165]=0; primes[1166]=0; primes[1167]=0; primes[1168]=0; primes[1169]=0; primes[1170]=0; primes[1171]=1; primes[1172]=0; primes[1173]=0; primes[1174]=0; primes[1175]=0; primes[1176]=0; primes[1177]=0; primes[1178]=0; primes[1179]=0; primes[1180]=0; primes[1181]=1; primes[1182]=0; primes[1183]=0; primes[1184]=0; primes[1185]=0; primes[1186]=0; primes[1187]=1; primes[1188]=0; primes[1189]=0; primes[1190]=0; primes[1191]=0; primes[1192]=0; primes[1193]=1; primes[1194]=0; primes[1195]=0; primes[1196]=0; primes[1197]=0; primes[1198]=0; primes[1199]=0;
    primes[1200]=0; primes[1201]=1; primes[1202]=0; primes[1203]=0; primes[1204]=0; primes[1205]=0; primes[1206]=0; primes[1207]=0; primes[1208]=0; primes[1209]=0; primes[1210]=0; primes[1211]=0; primes[1212]=0; primes[1213]=1; primes[1214]=0; primes[1215]=0; primes[1216]=0; primes[1217]=1; primes[1218]=0; primes[1219]=0; primes[1220]=0; primes[1221]=0; primes[1222]=0; primes[1223]=1; primes[1224]=0; primes[1225]=0; primes[1226]=0; primes[1227]=0; primes[1228]=0; primes[1229]=1; primes[1230]=0; primes[1231]=1; primes[1232]=0; primes[1233]=0; primes[1234]=0; primes[1235]=0; primes[1236]=0; primes[1237]=1; primes[1238]=0; primes[1239]=0; primes[1240]=0; primes[1241]=0; primes[1242]=0; primes[1243]=0; primes[1244]=0; primes[1245]=0; primes[1246]=0; primes[1247]=0; primes[1248]=0; primes[1249]=1; primes[1250]=0; primes[1251]=0; primes[1252]=0; primes[1253]=0; primes[1254]=0; primes[1255]=0; primes[1256]=0; primes[1257]=0; primes[1258]=0; primes[1259]=1; primes[1260]=0; primes[1261]=0; primes[1262]=0; primes[1263]=0; primes[1264]=0; primes[1265]=0; primes[1266]=0; primes[1267]=0; primes[1268]=0; primes[1269]=0; primes[1270]=0; primes[1271]=0; primes[1272]=0; primes[1273]=0; primes[1274]=0; primes[1275]=0; primes[1276]=0; primes[1277]=1; primes[1278]=0; primes[1279]=1; primes[1280]=0; primes[1281]=0; primes[1282]=0; primes[1283]=1; primes[1284]=0; primes[1285]=0; primes[1286]=0; primes[1287]=0; primes[1288]=0; primes[1289]=1; primes[1290]=0; primes[1291]=1; primes[1292]=0; primes[1293]=0; primes[1294]=0; primes[1295]=0; primes[1296]=0; primes[1297]=1; primes[1298]=0; primes[1299]=0; primes[1300]=0; primes[1301]=1; primes[1302]=0; primes[1303]=1; primes[1304]=0; primes[1305]=0; primes[1306]=0; primes[1307]=1; primes[1308]=0; primes[1309]=0; primes[1310]=0; primes[1311]=0; primes[1312]=0; primes[1313]=0; primes[1314]=0; primes[1315]=0; primes[1316]=0; primes[1317]=0; primes[1318]=0; primes[1319]=1;
    primes[1320]=0; primes[1321]=1; primes[1322]=0; primes[1323]=0; primes[1324]=0; primes[1325]=0; primes[1326]=0; primes[1327]=1; primes[1328]=0; primes[1329]=0; primes[1330]=0; primes[1331]=0; primes[1332]=0; primes[1333]=0; primes[1334]=0; primes[1335]=0; primes[1336]=0; primes[1337]=0; primes[1338]=0; primes[1339]=0; primes[1340]=0; primes[1341]=0; primes[1342]=0; primes[1343]=0; primes[1344]=0; primes[1345]=0; primes[1346]=0; primes[1347]=0; primes[1348]=0; primes[1349]=0; primes[1350]=0; primes[1351]=0; primes[1352]=0; primes[1353]=0; primes[1354]=0; primes[1355]=0; primes[1356]=0; primes[1357]=0; primes[1358]=0; primes[1359]=0; primes[1360]=0; primes[1361]=1; primes[1362]=0; primes[1363]=0; primes[1364]=0; primes[1365]=0; primes[1366]=0; primes[1367]=1; primes[1368]=0; primes[1369]=0; primes[1370]=0; primes[1371]=0; primes[1372]=0; primes[1373]=1; primes[1374]=0; primes[1375]=0; primes[1376]=0; primes[1377]=0; primes[1378]=0; primes[1379]=0; primes[1380]=0; primes[1381]=1; primes[1382]=0; primes[1383]=0; primes[1384]=0; primes[1385]=0; primes[1386]=0; primes[1387]=0; primes[1388]=0; primes[1389]=0; primes[1390]=0; primes[1391]=0; primes[1392]=0; primes[1393]=0; primes[1394]=0; primes[1395]=0; primes[1396]=0; primes[1397]=0; primes[1398]=0; primes[1399]=1; primes[1400]=0; primes[1401]=0; primes[1402]=0; primes[1403]=0; primes[1404]=0; primes[1405]=0; primes[1406]=0; primes[1407]=0; primes[1408]=0; primes[1409]=1; primes[1410]=0; primes[1411]=0; primes[1412]=0; primes[1413]=0; primes[1414]=0; primes[1415]=0; primes[1416]=0; primes[1417]=0; primes[1418]=0; primes[1419]=0; primes[1420]=0; primes[1421]=0; primes[1422]=0; primes[1423]=1; primes[1424]=0; primes[1425]=0; primes[1426]=0; primes[1427]=1; primes[1428]=0; primes[1429]=1; primes[1430]=0; primes[1431]=0; primes[1432]=0; primes[1433]=1; primes[1434]=0; primes[1435]=0; primes[1436]=0; primes[1437]=0; primes[1438]=0; primes[1439]=1;
    primes[1440]=0; primes[1441]=0; primes[1442]=0; primes[1443]=0; primes[1444]=0; primes[1445]=0; primes[1446]=0; primes[1447]=1; primes[1448]=0; primes[1449]=0; primes[1450]=0; primes[1451]=1; primes[1452]=0; primes[1453]=1; primes[1454]=0; primes[1455]=0; primes[1456]=0; primes[1457]=0;

    memset(tempo, -1, sizeof tempo);
    memset(sqvalues, -1, sizeof sqvalues);

    dp[0][0][0] = 1;
    for (int len = 0; len < MX_LEN-1; len++)
        for (int dig = 0; dig <= 9*len; dig++)
            for (int sq = 0; sq <= 81*len; sq++)
                for (int x = 0; x <= 9; x++)
                    dp[len+1][dig+x][sq+x*x] += dp[len][dig][sq];

    for (int len = 0; len < MX_LEN-1; len++)
    {
        for (int dig = 0; dig <= MX_SUM; dig++)
        {
            int p = 0;
            for (int sq = 0; sq <= 81*len; sq++)
                if (dp[len][dig][sq])
                    sqvalues[len][dig][p++] = sq;
        }
    }
}

LL count(LL X)
{
    LL res = 0;
    LL t = X;
    int digits[MX_LEN];
    int len = 0;
    while (t)
    {
        digits[len] = t % 10;
        t /= 10;
        len++;
    }

    int sum = 0, sumsq = 0;
    for (int i = len-1; i >= 0; i--)
    {
        LL step = 0;
        for (int num = 0; num < digits[i]; num++)
        {
            if (tempo[i][num][sum][sumsq] != -1)
                step += tempo[i][num][sum][sumsq];
            else
            {
                LL s = 0;
                for (int dig = 0; dig <= 9*i; dig++)
                    if (primes[dig + num + sum])
                    {
                        int p = 0;
                        while (sqvalues[i][dig][p] != -1)
                        {
                            int sq = sqvalues[i][dig][p];
                            if(primes[sq + num*num + sumsq])
                                s += dp[i][dig][sq];
                            p++;
                        }
                    }
                step += s;
                tempo[i][num][sum][sumsq] = s;
            }
        }
        res += step;

        sum += digits[i];
        sumsq += digits[i]*digits[i];
    }

    return res;
}

LL solve(LL A, LL B)
{
    return count(B+1)-count(A);
}

int main()
{
    int T;
    precompute();

    scanf("%d", &T);
    while (T--)
    {
        LL A,B;
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", solve(A,B));
    }
    return 0;
}

