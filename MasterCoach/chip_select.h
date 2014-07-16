/*
 * Select device-specific header file
 */

#ifndef _CHIP_SELECT_H_
#define _CHIP_SELECT_H_

#ifdef _16C558
#ifdef _LEGACY_HEADERS
#include <legacy/pic1655x.h>
#else
#include <pic16c558.h>
#endif
#endif

#ifdef _16C99C
#include <legacy/pic1699.h>
#endif

#ifdef _16LF1783
#include <pic16lf1783.h>
#endif

#ifdef _16F1823
#include <pic16f1823.h>
#endif

#ifdef _16F873A
#ifdef _LEGACY_HEADERS
#include <legacy/pic168xa.h>
#else
#include <pic16f873a.h>
#endif
#endif

#ifdef _16HV540
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16hv540.h>
#endif
#endif

#ifdef _12F635
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f636.h>
#else
#include <pic12f635.h>
#endif
#endif

#ifdef _16F627
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f6x.h>
#else
#include <pic16f627.h>
#endif
#endif

#ifdef _16F785
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f785.h>
#else
#include <pic16f785.h>
#endif
#endif

#ifdef _16F707
#include <pic16f707.h>
#endif

#ifdef _16HV616
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f616.h>
#else
#include <pic16hv616.h>
#endif
#endif

#ifdef _16F631
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f631.h>
#endif
#endif

#ifdef _16F777
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x7.h>
#else
#include <pic16f777.h>
#endif
#endif

#ifdef _16C65B
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c65b.h>
#endif
#endif

#ifdef _16F886
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f887.h>
#else
#include <pic16f886.h>
#endif
#endif

#ifdef _16LF1904
#include <pic16lf1904.h>
#endif

#ifdef _16F1847
#include <pic16f1847.h>
#endif

#ifdef _12HV615
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f615.h>
#else
#include <pic12hv615.h>
#endif
#endif

#ifdef _16C923
#ifdef _LEGACY_HEADERS
#include <legacy/pic169xx.h>
#else
#include <pic16c923.h>
#endif
#endif

#ifdef _16C58A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c58a.h>
#endif
#endif

#ifdef _16C745
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c745.h>
#endif
#endif

#ifdef _16F917
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f91x.h>
#else
#include <pic16f917.h>
#endif
#endif

#ifdef _12CR509A
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12cr509a.h>
#endif
#endif

#ifdef _16CR76
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677.h>
#else
#include <pic16cr76.h>
#endif
#endif

#ifdef _10F222
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f22x.h>
#else
#include <pic10f222.h>
#endif
#endif

#ifdef _16LF1903
#include <pic16lf1903.h>
#endif

#ifdef _16LF1939
#include <pic16lf1939.h>
#endif

#ifdef _16F687
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f687.h>
#endif
#endif

#ifdef _7C695X
#include <legacy/pic7695x.h>
#endif

#ifdef _16LF1946
#include <pic16lf1946.h>
#endif

#ifdef _16C771
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c771.h>
#endif
#endif

#ifdef _16F882
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f887.h>
#else
#include <pic16f882.h>
#endif
#endif

#ifdef _16C710
#ifdef _LEGACY_HEADERS
#include <legacy/pic1671x.h>
#else
#include <pic16c710.h>
#endif
#endif

#ifdef _16F1934
#include <pic16f1934.h>
#endif

#ifdef _16LF1907
#include <pic16lf1907.h>
#endif

#ifdef _12HV609
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f615.h>
#else
#include <pic12hv609.h>
#endif
#endif

#ifdef _16LF707
#include <pic16lf707.h>
#endif

#ifdef _RF675F
#include <picrf675f.h>
#endif

#ifdef _16C64A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1664.h>
#else
#include <pic16c64a.h>
#endif
#endif

#ifdef _16F1517
#include <pic16f1517.h>
#endif

#ifdef _10LF322
#include <pic10lf322.h>
#endif

#ifdef _16LF1527
#include <pic16lf1527.h>
#endif

#ifdef _RF675AF
#include <picrf675af.h>
#endif

#ifdef _12C671
#ifdef _LEGACY_HEADERS
#include <legacy/pic1267x.h>
#else
#include <pic12c671.h>
#endif
#endif

#ifdef _16F74
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x.h>
#else
#include <pic16f74.h>
#endif
#endif

#ifdef _16LF1517
#include <pic16lf1517.h>
#endif

#ifdef _16C66
#ifdef _LEGACY_HEADERS
#include <legacy/pic166x.h>
#else
#include <pic16c66.h>
#endif
#endif

#ifdef _16F913
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f91x.h>
#else
#include <pic16f913.h>
#endif
#endif

#ifdef _16C711
#ifdef _LEGACY_HEADERS
#include <legacy/pic1671x.h>
#else
#include <pic16c711.h>
#endif
#endif

#ifdef _16CR62
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662.h>
#else
#include <pic16cr62.h>
#endif
#endif

#ifdef _16C433
#ifdef _LEGACY_HEADERS
#include <legacy/pic1643x.h>
#else
#include <pic16c433.h>
#endif
#endif

#ifdef _16CR83
#ifdef _LEGACY_HEADERS
#include <legacy/pic1684.h>
#else
#include <pic16cr83.h>
#endif
#endif

#ifdef _16F872
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f872.h>
#endif
#endif

#ifdef _16CR57C
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr57c.h>
#endif
#endif

#ifdef _16C715
#ifdef _LEGACY_HEADERS
#include <legacy/pic16715.h>
#else
#include <pic16c715.h>
#endif
#endif

#ifdef _10F200
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f20x.h>
#else
#include <pic10f200.h>
#endif
#endif

#ifdef _16F636
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f636.h>
#else
#include <pic16f636.h>
#endif
#endif

#ifdef _10F220
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f22x.h>
#else
#include <pic10f220.h>
#endif
#endif

#ifdef _16F721
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f721.h>
#else
#include <pic16f721.h>
#endif
#endif

#ifdef _16C58B
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c58b.h>
#endif
#endif

#ifdef _16C621A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c621a.h>
#endif
#endif

#ifdef _16CR54B
#include <legacy/pic165x.h>
#endif

#ifdef _16C56
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c56.h>
#endif
#endif

#ifdef _16C74A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c74a.h>
#endif
#endif

#ifdef _16C63
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c63.h>
#endif
#endif

#ifdef _16LF1826
#include <pic16lf1826.h>
#endif

#ifdef _16F1939
#include <pic16f1939.h>
#endif

#ifdef _16C62B
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662.h>
#else
#include <pic16c62b.h>
#endif
#endif

#ifdef _16C55
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c55.h>
#endif
#endif

#ifdef _16F716
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f716.h>
#else
#include <pic16f716.h>
#endif
#endif

#ifdef _16C622
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c622.h>
#endif
#endif

#ifdef _16F887
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f887.h>
#else
#include <pic16f887.h>
#endif
#endif

#ifdef _16LF720
#ifdef _LEGACY_HEADERS
#include <legacy/pic16lf720.h>
#else
#include <pic16lf720.h>
#endif
#endif

#ifdef _16CR77
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677.h>
#else
#include <pic16cr77.h>
#endif
#endif

#ifdef _12F615
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f615.h>
#else
#include <pic12f615.h>
#endif
#endif

#ifdef _16C65A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1665.h>
#else
#include <pic16c65a.h>
#endif
#endif

#ifdef _12CE519
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12ce519.h>
#endif
#endif

#ifdef _16F628
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f6x.h>
#else
#include <pic16f628.h>
#endif
#endif

#ifdef _16C73B
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c73b.h>
#endif
#endif

#ifdef _16F54
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f5x.h>
#else
#include <pic16f54.h>
#endif
#endif

#ifdef _16F1829
#include <pic16f1829.h>
#endif

#ifdef _16CE625
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16ce625.h>
#endif
#endif

#ifdef _12F520
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f520.h>
#else
#include <pic12f520.h>
#endif
#endif

#ifdef _16C62
#include <legacy/pic1662.h>
#endif

#ifdef _10F202
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f20x.h>
#else
#include <pic10f202.h>
#endif
#endif

#ifdef _12F629
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f6x.h>
#else
#include <pic12f629.h>
#endif
#endif

#ifdef _16F610
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f616.h>
#else
#include <pic16f610.h>
#endif
#endif

#ifdef _16LF722A
#include <pic16lf722a.h>
#endif

#ifdef _16C99
#include <legacy/pic1699.h>
#endif

#ifdef _10F322
#include <pic10f322.h>
#endif

#ifdef _16F648A
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f62xa.h>
#else
#include <pic16f648a.h>
#endif
#endif

#ifdef _16C72
#ifdef _LEGACY_HEADERS
#include <legacy/pic1672.h>
#else
#include <pic16c72.h>
#endif
#endif

#ifdef _16F1526
#include <pic16f1526.h>
#endif

#ifdef _16F723A
#include <pic16f723a.h>
#endif

#ifdef _16F1933
#include <pic16f1933.h>
#endif

#ifdef _16CR926
#ifdef _LEGACY_HEADERS
#include <legacy/pic169xx.h>
#else
#include <pic16cr926.h>
#endif
#endif

#ifdef _16F727
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16f727.h>
#endif
#endif

#ifdef _16LF1825
#include <pic16lf1825.h>
#endif

#ifdef _16F84
#ifdef _LEGACY_HEADERS
#include <legacy/pic1684.h>
#else
#include <pic16f84.h>
#endif
#endif

#ifdef _12F675H
#include <legacy/pic12rf675.h>
#endif

#ifdef _12C509
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12c509.h>
#endif
#endif

#ifdef _16CR72
#ifdef _LEGACY_HEADERS
#include <legacy/pic1672.h>
#else
#include <pic16cr72.h>
#endif
#endif

#ifdef _12F752
#include <pic12f752.h>
#endif

#ifdef _16F526
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f526.h>
#else
#include <pic16f526.h>
#endif
#endif

#ifdef _16C770
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c770.h>
#endif
#endif

#ifdef _16LF1936
#include <pic16lf1936.h>
#endif

#ifdef _16C621
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c621.h>
#endif
#endif

#ifdef _12C672
#ifdef _LEGACY_HEADERS
#include <legacy/pic1267x.h>
#else
#include <pic12c672.h>
#endif
#endif

#ifdef _16F1947
#include <pic16f1947.h>
#endif

#ifdef _16C557
#ifdef _LEGACY_HEADERS
#include <legacy/pic1655x.h>
#else
#include <pic16c557.h>
#endif
#endif

#ifdef _16F722
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16f722.h>
#endif
#endif

#ifdef _16C774
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c774.h>
#endif
#endif

#ifdef _16F1826
#include <pic16f1826.h>
#endif

#ifdef _16LF1824
#include <pic16lf1824.h>
#endif

#ifdef _12F683
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f683.h>
#else
#include <pic12f683.h>
#endif
#endif

#ifdef _12F675F
#include <legacy/pic12rf675.h>
#endif

#ifdef _16C622A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c622a.h>
#endif
#endif

#ifdef _16C642
#ifdef _LEGACY_HEADERS
#include <legacy/pic166xx.h>
#else
#include <pic16c642.h>
#endif
#endif

#ifdef _16LF723A
#include <pic16lf723a.h>
#endif

#ifdef _16CR58A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr58a.h>
#endif
#endif

#ifdef _16LF1516
#include <pic16lf1516.h>
#endif

#ifdef _16F506
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f506.h>
#else
#include <pic16f506.h>
#endif
#endif

#ifdef _16LF1847
#include <pic16lf1847.h>
#endif

#ifdef _16C72A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1672.h>
#else
#include <pic16c72a.h>
#endif
#endif

#ifdef _16C76
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677.h>
#else
#include <pic16c76.h>
#endif
#endif

#ifdef _16C54
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c54.h>
#endif
#endif

#ifdef _16F873
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f873.h>
#endif
#endif

#ifdef _16F1938
#include <pic16f1938.h>
#endif

#ifdef _16CR63
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16cr63.h>
#endif
#endif

#ifdef _16C65
#include <legacy/pic1665.h>
#endif

#ifdef _16LF1933
#include <pic16lf1933.h>
#endif

#ifdef _16LF726
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16lf726.h>
#endif
#endif

#ifdef _16F639
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f636.h>
#else
#include <pic16f639.h>
#endif
#endif

#ifdef _16LF1829
#include <pic16lf1829.h>
#endif

#ifdef _16F818
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f81x.h>
#else
#include <pic16f818.h>
#endif
#endif

#ifdef _16C71
#ifdef _LEGACY_HEADERS
#include <legacy/pic1671x.h>
#else
#include <pic16c71.h>
#endif
#endif

#ifdef _12F509
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12f509.h>
#endif
#endif

#ifdef _10F206
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f20x.h>
#else
#include <pic10f206.h>
#endif
#endif

#ifdef _RF675AK
#include <picrf675ak.h>
#endif

#ifdef _16C556A
#include <legacy/pic1655x.h>
#endif

#ifdef _16HV610
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f616.h>
#else
#include <pic16hv610.h>
#endif
#endif

#ifdef _16F83
#ifdef _LEGACY_HEADERS
#include <legacy/pic1684.h>
#else
#include <pic16f83.h>
#endif
#endif

#ifdef _16F747
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x7.h>
#else
#include <pic16f747.h>
#endif
#endif

#ifdef _16LF721
#ifdef _LEGACY_HEADERS
#include <legacy/pic16lf721.h>
#else
#include <pic16lf721.h>
#endif
#endif

#ifdef _16F819
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f81x.h>
#else
#include <pic16f819.h>
#endif
#endif

#ifdef _16F870
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f870.h>
#endif
#endif

#ifdef _16F685
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f685.h>
#endif
#endif

#ifdef _16F1516
#include <pic16f1516.h>
#endif

#ifdef _16F689
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f689.h>
#endif
#endif

#ifdef _16F723
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16f723.h>
#endif
#endif

#ifdef _16CR54C
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr54c.h>
#endif
#endif

#ifdef _16CR57A
#include <pic16cr57a.h>
#endif

#ifdef _16F84A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1684.h>
#else
#include <pic16f84a.h>
#endif
#endif

#ifdef _16F59
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f5x.h>
#else
#include <pic16f59.h>
#endif
#endif

#ifdef _12HV752
#include <pic12hv752.h>
#endif

#ifdef _12F1822
#include <pic12f1822.h>
#endif

#ifdef _16F677
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f677.h>
#endif
#endif

#ifdef _16F628A
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f62xa.h>
#else
#include <pic16f628a.h>
#endif
#endif

#ifdef _16C925
#ifdef _LEGACY_HEADERS
#include <legacy/pic169xx.h>
#else
#include <pic16c925.h>
#endif
#endif

#ifdef _12C509AF
#include <legacy/pic125xx.h>
#endif

#ifdef _16C554A
#include <legacy/pic1655x.h>
#endif

#ifdef _16C505
#ifdef _LEGACY_HEADERS
#include <legacy/pic16505.h>
#else
#include <pic16c505.h>
#endif
#endif

#ifdef _16C54A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c54a.h>
#endif
#endif

#ifdef _12F1840
#include <pic12f1840.h>
#endif

#ifdef _16CR65
#ifdef _LEGACY_HEADERS
#include <legacy/pic1665.h>
#else
#include <pic16cr65.h>
#endif
#endif

#ifdef _16F1519
#include <pic16f1519.h>
#endif

#ifdef _12C509A
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12c509a.h>
#endif
#endif

#ifdef _16F877
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f877.h>
#endif
#endif

#ifdef _16C62A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662.h>
#else
#include <pic16c62a.h>
#endif
#endif

#ifdef _16C73
#include <legacy/pic1674.h>
#endif

#ifdef _16F57
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f5x.h>
#else
#include <pic16f57.h>
#endif
#endif

#ifdef _16F73
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x.h>
#else
#include <pic16f73.h>
#endif
#endif

#ifdef _16F876A
#ifdef _LEGACY_HEADERS
#include <legacy/pic168xa.h>
#else
#include <pic16f876a.h>
#endif
#endif

#ifdef _16C620A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c620a.h>
#endif
#endif

#ifdef _MCV14A
#ifdef _LEGACY_HEADERS
#include <legacy/mcv14a.h>
#else
#include <picmcv14a.h>
#endif
#endif

#ifdef _MCV18A
#ifdef _LEGACY_HEADERS
#include <legacy/mcv28a.h>
#else
#include <picmcv18a.h>
#endif
#endif

#ifdef _MCV28A
#ifdef _LEGACY_HEADERS
#include <legacy/mcv28a.h>
#else
#include <picmcv28a.h>
#endif
#endif

#ifdef _16F1937
#include <pic16f1937.h>
#endif

#ifdef _MCV08A
#ifdef _LEGACY_HEADERS
#include <legacy/mcv08a.h>
#else
#include <picmcv08a.h>
#endif
#endif

#ifdef _16F884
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f887.h>
#else
#include <pic16f884.h>
#endif
#endif

#ifdef _16CE624
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16ce624.h>
#endif
#endif

#ifdef _16F616
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f616.h>
#else
#include <pic16f616.h>
#endif
#endif

#ifdef _16HV785
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f785.h>
#else
#include <pic16hv785.h>
#endif
#endif

#ifdef _16C54C
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c54c.h>
#endif
#endif

#ifdef _16C54B
#include <legacy/pic165x.h>
#endif

#ifdef _12F510
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f510.h>
#else
#include <pic12f510.h>
#endif
#endif

#ifdef _12C508A
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12c508a.h>
#endif
#endif

#ifdef _RF675K
#include <picrf675k.h>
#endif

#ifdef _16LF1519
#include <pic16lf1519.h>
#endif

#ifdef _16F1946
#include <pic16f1946.h>
#endif

#ifdef _10LF320
#include <pic10lf320.h>
#endif

#ifdef _16F1783
#include <pic16f1783.h>
#endif

#ifdef _16C620
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16c620.h>
#endif
#endif

#ifdef _16F627A
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f62xa.h>
#else
#include <pic16f627a.h>
#endif
#endif

#ifdef _16C782
#ifdef _LEGACY_HEADERS
#include <legacy/pic1678x.h>
#else
#include <pic16c782.h>
#endif
#endif

#ifdef _16F767
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x7.h>
#else
#include <pic16f767.h>
#endif
#endif

#ifdef _12CE518
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12ce518.h>
#endif
#endif

#ifdef _16C556
#include <legacy/pic1655x.h>
#endif

#ifdef _16F737
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x7.h>
#else
#include <pic16f737.h>
#endif
#endif

#ifdef _16LF1934
#include <pic16lf1934.h>
#endif

#ifdef _16F72
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x.h>
#else
#include <pic16f72.h>
#endif
#endif

#ifdef _16F946
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f946.h>
#else
#include <pic16f946.h>
#endif
#endif

#ifdef _16C926
#ifdef _LEGACY_HEADERS
#include <legacy/pic169xx.h>
#else
#include <pic16c926.h>
#endif
#endif

#ifdef _16LF722
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16lf722.h>
#endif
#endif

#ifdef _16F726
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16f726.h>
#endif
#endif

#ifdef _16LF1782
#include <pic16lf1782.h>
#endif

#ifdef _12F508
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12f508.h>
#endif
#endif

#ifdef _16F505
#ifdef _LEGACY_HEADERS
#include <legacy/pic16505.h>
#else
#include <pic16f505.h>
#endif
#endif

#ifdef _16LF1937
#include <pic16lf1937.h>
#endif

#ifdef _16LF1823
#include <pic16lf1823.h>
#endif

#ifdef _16F1825
#include <pic16f1825.h>
#endif

#ifdef _12LF1822
#include <pic12lf1822.h>
#endif

#ifdef _12F609
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f615.h>
#else
#include <pic12f609.h>
#endif
#endif

#ifdef _16F1527
#include <pic16f1527.h>
#endif

#ifdef _16F874
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f874.h>
#endif
#endif

#ifdef _16LF1828
#include <pic16lf1828.h>
#endif

#ifdef _16F1828
#include <pic16f1828.h>
#endif

#ifdef _RF675AH
#include <picrf675ah.h>
#endif

#ifdef _RF675H
#include <picrf675h.h>
#endif

#ifdef _16LF727
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16lf727.h>
#endif
#endif

#ifdef _16C641
#include <legacy/pic166xx.h>
#endif

#ifdef _16C773
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c773.h>
#endif
#endif

#ifdef _16C73A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c73a.h>
#endif
#endif

#ifdef _16C58
#include <legacy/pic165x.h>
#endif

#ifdef _12C508
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <pic12c508.h>
#endif
#endif

#ifdef _12F617
#include <pic12f617.h>
#endif

#ifdef _16CR56A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr56a.h>
#endif
#endif

#ifdef _16C77
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677.h>
#else
#include <pic16c77.h>
#endif
#endif

#ifdef _16F684
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f684.h>
#else
#include <pic16f684.h>
#endif
#endif

#ifdef _16C74
#include <legacy/pic1674.h>
#endif

#ifdef _16F916
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f91x.h>
#else
#include <pic16f916.h>
#endif
#endif

#ifdef _16C67
#ifdef _LEGACY_HEADERS
#include <legacy/pic166x.h>
#else
#include <pic16c67.h>
#endif
#endif

#ifdef _16CE623
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16ce623.h>
#endif
#endif

#ifdef _16C57C
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c57c.h>
#endif
#endif

#ifdef _16C717
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c717.h>
#endif
#endif

#ifdef _16F630
#ifdef _LEGACY_HEADERS
#include <legacy/pic16630.h>
#else
#include <pic16f630.h>
#endif
#endif

#ifdef _16F688
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f688.h>
#else
#include <pic16f688.h>
#endif
#endif

#ifdef _16F720
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f720.h>
#else
#include <pic16f720.h>
#endif
#endif

#ifdef _16CR57B
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr57b.h>
#endif
#endif

#ifdef _12F519
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f519.h>
#else
#include <pic12f519.h>
#endif
#endif

#ifdef _16CR64
#ifdef _LEGACY_HEADERS
#include <legacy/pic1664.h>
#else
#include <pic16cr64.h>
#endif
#endif

#ifdef _16C661
#include <legacy/pic166xx.h>
#endif

#ifdef _16F1936
#include <pic16f1936.h>
#endif

#ifdef _16C554
#ifdef _LEGACY_HEADERS
#include <legacy/pic1655x.h>
#else
#include <pic16c554.h>
#endif
#endif

#ifdef _16LF1902
#include <pic16lf1902.h>
#endif

#ifdef _12F675
#ifdef _LEGACY_HEADERS
#include <legacy/pic12f6x.h>
#else
#include <pic12f675.h>
#endif
#endif

#ifdef _16F676
#ifdef _LEGACY_HEADERS
#include <legacy/pic16630.h>
#else
#include <pic16f676.h>
#endif
#endif

#ifdef _16F87
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f87.h>
#else
#include <pic16f87.h>
#endif
#endif

#ifdef _RF509AG
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <picrf509ag.h>
#endif
#endif

#ifdef _10F320
#include <pic10f320.h>
#endif

#ifdef _16F77
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x.h>
#else
#include <pic16f77.h>
#endif
#endif

#ifdef _16LF1827
#include <pic16lf1827.h>
#endif

#ifdef _16F1827
#include <pic16f1827.h>
#endif

#ifdef _16F1824
#include <pic16f1824.h>
#endif

#ifdef _16F690
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f685.h>
#else
#include <pic16f690.h>
#endif
#endif

#ifdef _16CR84
#ifdef _LEGACY_HEADERS
#include <legacy/pic1684.h>
#else
#include <pic16cr84.h>
#endif
#endif

#ifdef _16LF1518
#include <pic16lf1518.h>
#endif

#ifdef _16C924
#ifdef _LEGACY_HEADERS
#include <legacy/pic169xx.h>
#else
#include <pic16c924.h>
#endif
#endif

#ifdef _12CE674
#ifdef _LEGACY_HEADERS
#include <legacy/pic1267x.h>
#else
#include <pic12ce674.h>
#endif
#endif

#ifdef _16LF1938
#include <pic16lf1938.h>
#endif

#ifdef _16CR58B
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr58b.h>
#endif
#endif

#ifdef _16C781
#ifdef _LEGACY_HEADERS
#include <legacy/pic1678x.h>
#else
#include <pic16c781.h>
#endif
#endif

#ifdef _16F876
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f876.h>
#endif
#endif

#ifdef _16C57
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c57.h>
#endif
#endif

#ifdef _16C63A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c63a.h>
#endif
#endif

#ifdef _12C509AG
#include <legacy/pic125xx.h>
#endif

#ifdef _16F722A
#include <pic16f722a.h>
#endif

#ifdef _16C712
#ifdef _LEGACY_HEADERS
#include <legacy/pic16715.h>
#else
#include <pic16c712.h>
#endif
#endif

#ifdef _16F724
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16f724.h>
#endif
#endif

#ifdef _16CR74
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16cr74.h>
#endif
#endif

#ifdef _16CR73
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16cr73.h>
#endif
#endif

#ifdef _16F883
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f887.h>
#else
#include <pic16f883.h>
#endif
#endif

#ifdef _16C716
#ifdef _LEGACY_HEADERS
#include <legacy/pic16715.h>
#else
#include <pic16c716.h>
#endif
#endif

#ifdef _16F874A
#ifdef _LEGACY_HEADERS
#include <legacy/pic168xa.h>
#else
#include <pic16f874a.h>
#endif
#endif

#ifdef _16C84
#include <legacy/pic1684.h>
#endif

#ifdef _MCV18E
#include <picmcv18e.h>
#endif

#ifdef _12F675K
#include <legacy/pic12rf675.h>
#endif

#ifdef _16F1782
#include <pic16f1782.h>
#endif

#ifdef _12CE673
#ifdef _LEGACY_HEADERS
#include <legacy/pic1267x.h>
#else
#include <pic12ce673.h>
#endif
#endif

#ifdef _16LC74B
#include <legacy/pic1674.h>
#endif

#ifdef _16F877A
#ifdef _LEGACY_HEADERS
#include <legacy/pic168xa.h>
#else
#include <pic16f877a.h>
#endif
#endif

#ifdef _16C52
#include <legacy/pic165x.h>
#endif

#ifdef _16C56A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c56a.h>
#endif
#endif

#ifdef _16F914
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f91x.h>
#else
#include <pic16f914.h>
#endif
#endif

#ifdef _16C765
#ifdef _LEGACY_HEADERS
#include <legacy/pic1677x.h>
#else
#include <pic16c765.h>
#endif
#endif

#ifdef _10F204
#ifdef _LEGACY_HEADERS
#include <legacy/pic10f20x.h>
#else
#include <pic10f204.h>
#endif
#endif

#ifdef _16CR54A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr54a.h>
#endif
#endif

#ifdef _16LF1906
#include <pic16lf1906.h>
#endif

#ifdef _16C558A
#include <legacy/pic1655x.h>
#endif

#ifdef _16CR54
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16cr54.h>
#endif
#endif

#ifdef _16F1518
#include <pic16f1518.h>
#endif

#ifdef _16LF1526
#include <pic16lf1526.h>
#endif

#ifdef _16LF1947
#include <pic16lf1947.h>
#endif

#ifdef _16LF723
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16lf723.h>
#endif
#endif

#ifdef _16LF724
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f72x.h>
#else
#include <pic16lf724.h>
#endif
#endif

#ifdef _16CR620A
#ifdef _LEGACY_HEADERS
#include <legacy/pic1662x.h>
#else
#include <pic16cr620a.h>
#endif
#endif

#ifdef _16F88
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f87.h>
#else
#include <pic16f88.h>
#endif
#endif

#ifdef _16C64
#include <legacy/pic1664.h>
#endif

#ifdef _RF509AF
#ifdef _LEGACY_HEADERS
#include <legacy/pic125xx.h>
#else
#include <picrf509af.h>
#endif
#endif

#ifdef _12LF1840
#include <pic12lf1840.h>
#endif

#ifdef _16C74B
#ifdef _LEGACY_HEADERS
#include <legacy/pic1674.h>
#else
#include <pic16c74b.h>
#endif
#endif

#ifdef _16F871
#ifdef _LEGACY_HEADERS
#include <legacy/pic1687x.h>
#else
#include <pic16f871.h>
#endif
#endif

#ifdef _16C432
#ifdef _LEGACY_HEADERS
#include <legacy/pic1643x.h>
#else
#include <pic16c432.h>
#endif
#endif

#ifdef _16F76
#ifdef _LEGACY_HEADERS
#include <legacy/pic16f7x.h>
#else
#include <pic16f76.h>
#endif
#endif

#ifdef _16C55A
#ifdef _LEGACY_HEADERS
#include <legacy/pic165x.h>
#else
#include <pic16c55a.h>
#endif
#endif

#ifdef _16C662
#ifdef _LEGACY_HEADERS
#include <legacy/pic166xx.h>
#else
#include <pic16c662.h>
#endif
#endif

#endif
