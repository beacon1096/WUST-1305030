#ifndef BF_ABOUTDIALOG
#define BF_ABOUTDIALOG

#define BF_ABOUTDIALOGVERSION "1.0.0"

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QDialog>
#include <QLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QTextBrowser>
#include <QDebug>
#include <QDialogButtonBox>
#include <QApplication>
#include <QFontDatabase>
#include <QScrollBar>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QStyle>

#include "BeaconFrameworks.hpp"
#include "BeaconFileIO.hpp"

class QVBoxLayout;
class QHBoxLayout;
class QTabWidget;
class QTextBrowser;

class BeaconAboutPerson{
public:
    explicit BeaconAboutPerson(const QString &name = QString(),
                             const QString &task = QString(),
                             const QString &emailAddress = QString(),
                             const QString &webAddress = QString(),
                             const QString &ocsUsername = QString())
    {
        _name = name;
        _task = task;
        _emailAddress = emailAddress;
        _webAddress = webAddress;
        _ocsUsername = ocsUsername;
    }
    BeaconAboutPerson(const BeaconAboutPerson &other)
    {
        _name = other.name();
        _task = other.task();
        _emailAddress = other.emailAddress();
        _webAddress = other.webAddress();
        _ocsUsername = other.ocsUsername();
    }
    ~BeaconAboutPerson()
    {
    }
    BeaconAboutPerson &operator=(const BeaconAboutPerson &other)
    {
        _name = other.name();
        _task = other.task();
        _emailAddress = other.emailAddress();
        _webAddress = other.webAddress();
        _ocsUsername = other.ocsUsername();
        return *this;
    }
    QString name() const{return _name;}
    QString task() const{return _task;}
    QString emailAddress() const{return _emailAddress;}
    QString webAddress() const{return _webAddress;}
    QString ocsUsername() const{return _ocsUsername;}
private:
    //JSON Support will be improved in the future
    QString _name;
    QString _task;
    QString _emailAddress;
    QString _webAddress;
    QString _ocsUsername;
};

class BeaconAboutLicenseContent{
public:
    BeaconAboutLicenseContent()
    {

    }
    const static QString GPL(){
        return QString("                    GNU GENERAL PUBLIC LICENSE\n"
                       "                       Version 2, June 1991\n"
                       "\n"
                       " Copyright (C) 1989, 1991 Free Software Foundation, Inc.,\n"
                       " 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA\n"
                       " Everyone is permitted to copy and distribute verbatim copies\n"
                       " of this license document, but changing it is not allowed.\n"
                       "\n"
                       "                            Preamble\n"
                       "\n"
                       "  The licenses for most software are designed to take away your\n"
                       "freedom to share and change it.  By contrast, the GNU General Public\n"
                       "License is intended to guarantee your freedom to share and change free\n"
                       "software--to make sure the software is free for all its users.  This\n"
                       "General Public License applies to most of the Free Software\n"
                       "Foundation's software and to any other program whose authors commit to\n"
                       "using it.  (Some other Free Software Foundation software is covered by\n"
                       "the GNU Lesser General Public License instead.)  You can apply it to\n"
                       "your programs, too.\n"
                       "\n"
                       "  When we speak of free software, we are referring to freedom, not\n"
                       "price.  Our General Public Licenses are designed to make sure that you\n"
                       "have the freedom to distribute copies of free software (and charge for\n"
                       "this service if you wish), that you receive source code or can get it\n"
                       "if you want it, that you can change the software or use pieces of it\n"
                       "in new free programs; and that you know you can do these things.\n"
                       "\n"
                       "  To protect your rights, we need to make restrictions that forbid\n"
                       "anyone to deny you these rights or to ask you to surrender the rights.\n"
                       "These restrictions translate to certain responsibilities for you if you\n"
                       "distribute copies of the software, or if you modify it.\n"
                       "\n"
                       "  For example, if you distribute copies of such a program, whether\n"
                       "gratis or for a fee, you must give the recipients all the rights that\n"
                       "you have.  You must make sure that they, too, receive or can get the\n"
                       "source code.  And you must show them these terms so they know their\n"
                       "rights.\n"
                       "\n"
                       "  We protect your rights with two steps: (1) copyright the software, and\n"
                       "(2) offer you this license which gives you legal permission to copy,\n"
                       "distribute and/or modify the software.\n"
                       "\n"
                       "  Also, for each author's protection and ours, we want to make certain\n"
                       "that everyone understands that there is no warranty for this free\n"
                       "software.  If the software is modified by someone else and passed on, we\n"
                       "want its recipients to know that what they have is not the original, so\n"
                       "that any problems introduced by others will not reflect on the original\n"
                       "authors' reputations.\n"
                       "\n"
                       "  Finally, any free program is threatened constantly by software\n"
                       "patents.  We wish to avoid the danger that redistributors of a free\n"
                       "program will individually obtain patent licenses, in effect making the\n"
                       "program proprietary.  To prevent this, we have made it clear that any\n"
                       "patent must be licensed for everyone's free use or not licensed at all.\n"
                       "\n"
                       "  The precise terms and conditions for copying, distribution and\n"
                       "modification follow.\n"
                       "\n"
                       "                    GNU GENERAL PUBLIC LICENSE\n"
                       "   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION\n"
                       "\n"
                       "  0. This License applies to any program or other work which contains\n"
                       "a notice placed by the copyright holder saying it may be distributed\n"
                       "under the terms of this General Public License.  The \"Program\", below,\n"
                       "refers to any such program or work, and a \"work based on the Program\"\n"
                       "means either the Program or any derivative work under copyright law:\n"
                       "that is to say, a work containing the Program or a portion of it,\n"
                       "either verbatim or with modifications and/or translated into another\n"
                       "language.  (Hereinafter, translation is included without limitation in\n"
                       "the term \"modification\".)  Each licensee is addressed as \"you\".\n"
                       "\n"
                       "Activities other than copying, distribution and modification are not\n"
                       "covered by this License; they are outside its scope.  The act of\n"
                       "running the Program is not restricted, and the output from the Program\n"
                       "is covered only if its contents constitute a work based on the\n"
                       "Program (independent of having been made by running the Program).\n"
                       "Whether that is true depends on what the Program does.\n"
                       "\n"
                       "  1. You may copy and distribute verbatim copies of the Program's\n"
                       "source code as you receive it, in any medium, provided that you\n"
                       "conspicuously and appropriately publish on each copy an appropriate\n"
                       "copyright notice and disclaimer of warranty; keep intact all the\n"
                       "notices that refer to this License and to the absence of any warranty;\n"
                       "and give any other recipients of the Program a copy of this License\n"
                       "along with the Program.\n"
                       "\n"
                       "You may charge a fee for the physical act of transferring a copy, and\n"
                       "you may at your option offer warranty protection in exchange for a fee.\n"
                       "\n"
                       "  2. You may modify your copy or copies of the Program or any portion\n"
                       "of it, thus forming a work based on the Program, and copy and\n"
                       "distribute such modifications or work under the terms of Section 1\n"
                       "above, provided that you also meet all of these conditions:\n"
                       "\n"
                       "    a) You must cause the modified files to carry prominent notices\n"
                       "    stating that you changed the files and the date of any change.\n"
                       "\n"
                       "    b) You must cause any work that you distribute or publish, that in\n"
                       "    whole or in part contains or is derived from the Program or any\n"
                       "    part thereof, to be licensed as a whole at no charge to all third\n"
                       "    parties under the terms of this License.\n"
                       "\n"
                       "    c) If the modified program normally reads commands interactively\n"
                       "    when run, you must cause it, when started running for such\n"
                       "    interactive use in the most ordinary way, to print or display an\n"
                       "    announcement including an appropriate copyright notice and a\n"
                       "    notice that there is no warranty (or else, saying that you provide\n"
                       "    a warranty) and that users may redistribute the program under\n"
                       "    these conditions, and telling the user how to view a copy of this\n"
                       "    License.  (Exception: if the Program itself is interactive but\n"
                       "    does not normally print such an announcement, your work based on\n"
                       "    the Program is not required to print an announcement.)\n"
                       "\n"
                       "These requirements apply to the modified work as a whole.  If\n"
                       "identifiable sections of that work are not derived from the Program,\n"
                       "and can be reasonably considered independent and separate works in\n"
                       "themselves, then this License, and its terms, do not apply to those\n"
                       "sections when you distribute them as separate works.  But when you\n"
                       "distribute the same sections as part of a whole which is a work based\n"
                       "on the Program, the distribution of the whole must be on the terms of\n"
                       "this License, whose permissions for other licensees extend to the\n"
                       "entire whole, and thus to each and every part regardless of who wrote it.\n"
                       "\n"
                       "Thus, it is not the intent of this section to claim rights or contest\n"
                       "your rights to work written entirely by you; rather, the intent is to\n"
                       "exercise the right to control the distribution of derivative or\n"
                       "collective works based on the Program.\n"
                       "\n"
                       "In addition, mere aggregation of another work not based on the Program\n"
                       "with the Program (or with a work based on the Program) on a volume of\n"
                       "a storage or distribution medium does not bring the other work under\n"
                       "the scope of this License.\n"
                       "\n"
                       "  3. You may copy and distribute the Program (or a work based on it,\n"
                       "under Section 2) in object code or executable form under the terms of\n"
                       "Sections 1 and 2 above provided that you also do one of the following:"
                       "\n"
                       "    a) Accompany it with the complete corresponding machine-readable\n"
                       "    source code, which must be distributed under the terms of Sections\n"
                       "    1 and 2 above on a medium customarily used for software interchange; or,\n"
                       "\n"
                       "    b) Accompany it with a written offer, valid for at least three\n"
                       "    years, to give any third party, for a charge no more than your\n"
                       "    cost of physically performing source distribution, a complete\n"
                       "    machine-readable copy of the corresponding source code, to be\n"
                       "    distributed under the terms of Sections 1 and 2 above on a medium\n"
                       "    customarily used for software interchange; or,\n"
                       "\n"
                       "    c) Accompany it with the information you received as to the offer\n"
                       "    to distribute corresponding source code.  (This alternative is\n"
                       "    allowed only for noncommercial distribution and only if you\n"
                       "    received the program in object code or executable form with such\n"
                       "    an offer, in accord with Subsection b above.)\n"
                       "\n"
                       "The source code for a work means the preferred form of the work for\n"
                       "making modifications to it.  For an executable work, complete source\n"
                       "code means all the source code for all modules it contains, plus any\n"
                       "associated interface definition files, plus the scripts used to\n"
                       "control compilation and installation of the executable.  However, as a\n"
                       "special exception, the source code distributed need not include\n"
                       "anything that is normally distributed (in either source or binary\n"
                       "form) with the major components (compiler, kernel, and so on) of the\n"
                       "operating system on which the executable runs, unless that component\n"
                       "itself accompanies the executable.\n"
                       "\n"
                       "If distribution of executable or object code is made by offering\n"
                       "access to copy from a designated place, then offering equivalent\n"
                       "access to copy the source code from the same place counts as\n"
                       "distribution of the source code, even though third parties are not\n"
                       "compelled to copy the source along with the object code.\n"
                       "\n"
                       "  4. You may not copy, modify, sublicense, or distribute the Program\n"
                       "except as expressly provided under this License.  Any attempt\n"
                       "otherwise to copy, modify, sublicense or distribute the Program is\n"
                       "void, and will automatically terminate your rights under this License.\n"
                       "However, parties who have received copies, or rights, from you under\n"
                       "this License will not have their licenses terminated so long as such\n"
                       "parties remain in full compliance.\n"
                       "\n"
                       "  5. You are not required to accept this License, since you have not\n"
                       "signed it.  However, nothing else grants you permission to modify or\n"
                       "distribute the Program or its derivative works.  These actions are\n"
                       "prohibited by law if you do not accept this License.  Therefore, by\n"
                       "modifying or distributing the Program (or any work based on the\n"
                       "Program), you indicate your acceptance of this License to do so, and\n"
                       "all its terms and conditions for copying, distributing or modifying\n"
                       "the Program or works based on it.\n"
                       "\n"
                       "  6. Each time you redistribute the Program (or any work based on the\n"
                       "Program), the recipient automatically receives a license from the\n"
                       "original licensor to copy, distribute or modify the Program subject to\n"
                       "these terms and conditions.  You may not impose any further\n"
                       "restrictions on the recipients' exercise of the rights granted herein.\n"
                       "You are not responsible for enforcing compliance by third parties to\n"
                       "this License.\n"
                       "\n"
                       "  7. If, as a consequence of a court judgment or allegation of patent\n"
                       "infringement or for any other reason (not limited to patent issues),\n"
                       "conditions are imposed on you (whether by court order, agreement or\n"
                       "otherwise) that contradict the conditions of this License, they do not\n"
                       "excuse you from the conditions of this License.  If you cannot\n"
                       "distribute so as to satisfy simultaneously your obligations under this\n"
                       "License and any other pertinent obligations, then as a consequence you\n"
                       "may not distribute the Program at all.  For example, if a patent\n"
                       "license would not permit royalty-free redistribution of the Program by\n"
                       "all those who receive copies directly or indirectly through you, then\n"
                       "the only way you could satisfy both it and this License would be to\n"
                       "refrain entirely from distribution of the Program.\n"
                       "\n"
                       "If any portion of this section is held invalid or unenforceable under\n"
                       "any particular circumstance, the balance of the section is intended to\n"
                       "apply and the section as a whole is intended to apply in other\n"
                       "circumstances.\n"
                       "\n"
                       "It is not the purpose of this section to induce you to infringe any\n"
                       "patents or other property right claims or to contest validity of any\n"
                       "such claims; this section has the sole purpose of protecting the\n"
                       "integrity of the free software distribution system, which is\n"
                       "implemented by public license practices.  Many people have made\n"
                       "generous contributions to the wide range of software distributed\n"
                       "through that system in reliance on consistent application of that\n"
                       "system; it is up to the author/donor to decide if he or she is willing\n"
                       "to distribute software through any other system and a licensee cannot\n"
                       "impose that choice.\n"
                       "\n"
                       "This section is intended to make thoroughly clear what is believed to\n"
                       "be a consequence of the rest of this License.\n"
                       "\n"
                       "  8. If the distribution and/or use of the Program is restricted in\n"
                       "certain countries either by patents or by copyrighted interfaces, the\n"
                       "original copyright holder who places the Program under this License\n"
                       "may add an explicit geographical distribution limitation excluding\n"
                       "those countries, so that distribution is permitted only in or among\n"
                       "countries not thus excluded.  In such case, this License incorporates\n"
                       "the limitation as if written in the body of this License.\n"
                       "\n"
                       "  9. The Free Software Foundation may publish revised and/or new versions\n"
                       "of the General Public License from time to time.  Such new versions will\n"
                       "be similar in spirit to the present version, but may differ in detail to\n"
                       "address new problems or concerns.\n"
                       "\n"
                       "Each version is given a distinguishing version number.  If the Program\n"
                       "specifies a version number of this License which applies to it and \"any\n"
                       "later version\", you have the option of following the terms and conditions\n"
                       "either of that version or of any later version published by the Free\n"
                       "Software Foundation.  If the Program does not specify a version number of\n"
                       "this License, you may choose any version ever published by the Free Software\n"
                       "Foundation.\n"
                       "\n"
                       "  10. If you wish to incorporate parts of the Program into other free\n"
                       "programs whose distribution conditions are different, write to the author\n"
                       "to ask for permission.  For software which is copyrighted by the Free\n"
                       "Software Foundation, write to the Free Software Foundation; we sometimes\n"
                       "make exceptions for this.  Our decision will be guided by the two goals\n"
                       "of preserving the free status of all derivatives of our free software and\n"
                       "of promoting the sharing and reuse of software generally.\n"
                       "\n"
                       "                            NO WARRANTY\n"
                       "\n"
                       "  11. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY\n"
                       "FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.  EXCEPT WHEN\n"
                       "OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES\n"
                       "PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED\n"
                       "OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF\n"
                       "MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE ENTIRE RISK AS\n"
                       "TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE\n"
                       "PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING,\n"
                       "REPAIR OR CORRECTION.\n"
                       "\n"
                       "  12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\n"
                       "WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR\n"
                       "REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,\n"
                       "INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING\n"
                       "OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED\n"
                       "TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY\n"
                       "YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER\n"
                       "PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE\n"
                       "POSSIBILITY OF SUCH DAMAGES.\n"
                       "\n"
                       "                     END OF TERMS AND CONDITIONS\n"
                       "\n"
                       "            How to Apply These Terms to Your New Programs\n"
                       "\n"
                       "  If you develop a new program, and you want it to be of the greatest\n"
                       "possible use to the public, the best way to achieve this is to make it\n"
                       "free software which everyone can redistribute and change under these terms.\n"
                       "\n"
                       "  To do so, attach the following notices to the program.  It is safest\n"
                       "to attach them to the start of each source file to most effectively\n"
                       "convey the exclusion of warranty; and each file should have at least\n"
                       "the \"copyright\" line and a pointer to where the full notice is found.\n"
                       "\n"
                       "    <one line to give the program's name and a brief idea of what it does.>\n"
                       "    Copyright (C) <year>  <name of author>\n"
                       "\n"
                       "    This program is free software; you can redistribute it and/or modify\n"
                       "    it under the terms of the GNU General Public License as published by\n"
                       "    the Free Software Foundation; either version 2 of the License, or\n"
                       "    (at your option) any later version.\n"
                       "\n"
                       "    This program is distributed in the hope that it will be useful,\n"
                       "    but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                       "    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
                       "    GNU General Public License for more details.\n"
                       "\n"
                       "    You should have received a copy of the GNU General Public License along\n"
                       "    with this program; if not, write to the Free Software Foundation, Inc.,\n"
                       "    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.\n"
                       "\n"
                       "Also add information on how to contact you by electronic and paper mail.\n"
                       "\n"
                       "If the program is interactive, make it output a short notice like this\n"
                       "when it starts in an interactive mode:\n"
                       "\n"
                       "    Gnomovision version 69, Copyright (C) year name of author\n"
                       "    Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
                       "    This is free software, and you are welcome to redistribute it\n"
                       "    under certain conditions; type `show c' for details.\n"
                       "\n"
                       "The hypothetical commands `show w' and `show c' should show the appropriate\n"
                       "parts of the General Public License.  Of course, the commands you use may\n"
                       "be called something other than `show w' and `show c'; they could even be\n"
                       "mouse-clicks or menu items--whatever suits your program.\n"
                       "\n"
                       "You should also get your employer (if you work as a programmer) or your\n"
                       "school, if any, to sign a \"copyright disclaimer\" for the program, if\n"
                       "necessary.  Here is a sample; alter the names:\n"
                       "\n"
                       "  Yoyodyne, Inc., hereby disclaims all copyright interest in the program\n"
                       "  `Gnomovision' (which makes passes at compilers) written by James Hacker.\n"
                       "\n"
                       "  <signature of Ty Coon>, 1 April 1989\n"
                       "  Ty Coon, President of Vice\n"
                       "\n"
                       "This General Public License does not permit incorporating your program into\n"
                       "proprietary programs.  If your program is a subroutine library, you may\n"
                       "consider it more useful to permit linking proprietary applications with the\n"
                       "library.  If this is what you want to do, use the GNU Lesser General\n"
                       "Public License instead of this License.");
    }
    const static QString LGPL(){return "LGPL";}
    const static QString BSDL(){
        return QString("Redistribution and use in source and binary forms, with or without\n"
                       "modification, are permitted provided that the following conditions\n"
                       "are met:\n"
                       "\n"
                       "1. Redistributions of source code must retain the above copyright\n"
                       "   notice, this list of conditions and the following disclaimer.\n"
                       "2. Redistributions in binary form must reproduce the above copyright\n"
                       "   notice, this list of conditions and the following disclaimer in the\n"
                       "   documentation and/or other materials provided with the distribution.\n"
                       "\n"
                       "THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR\n"
                       "IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES\n"
                       "OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.\n"
                       "IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,\n"
                       "INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT\n"
                       "NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n"
                       "DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n"
                       "THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
                       "(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF\n"
                       "THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    }
    const static QString Artistic(){return "Artistic";}
    const static QString QPL(){return "QPL";}
    const static QString GPL_V3(){return "GPL_V3";}
    const static QString LGPL_V3(){return "LGPL_V3";}
    const static QString LGPL_V2_1(){return "LGPL_V2_1";}
};

class BeaconAboutLicense : public QObject{
    Q_OBJECT
    friend class BeaconAboutData;
public:
    enum LicenseKey {
            Custom = -2,
            File = -1,
            Unknown = 0,
            GPL  = 1,
            GPL_V2 = 1,
            LGPL = 2,
            LGPL_V2 = 2,
            BSDL = 3,
            Artistic = 4,
            QPL = 5,
            QPL_V1_0 = 5,
            GPL_V3 = 6,
            LGPL_V3 = 7,
            LGPL_V2_1 = 8
        };
    enum NameFormat {
        ShortName,
        FullName
    };
    enum VersionRestriction {
        OnlyThisVersion,
        OrLaterVersions
    };
    explicit BeaconAboutLicense(BeaconAboutLicense::LicenseKey license = LicenseKey::Unknown,
                                BeaconAboutLicense::NameFormat nameFormat = NameFormat::FullName,
                                BeaconAboutLicense::VersionRestriction versionRestriction = VersionRestriction::OrLaterVersions)
    {
        _licenseKey = license;
        _nameFormat = nameFormat;
        _versionRestriction = versionRestriction;
        _updateText();
    }
    BeaconAboutLicense(const BeaconAboutLicense &other)
    {
        _licenseKey = other._licenseKey;
        _nameFormat = other._nameFormat;
        _versionRestriction = other._versionRestriction;
        _updateText();
    }
    ~BeaconAboutLicense(){}
    BeaconAboutLicense &operator=(const BeaconAboutLicense &other)
    {
        _licenseKey = other._licenseKey;
        _nameFormat = other._nameFormat;
        _versionRestriction = other._versionRestriction;
        _updateText();
        return *this;
    }
    QString text() const{return _licenseText;}
    BeaconAboutLicense::LicenseKey key() const{return _licenseKey;}
    QString name(BeaconAboutLicense::NameFormat formatName = ShortName) const
    {
        QString licenseShort;
        QString licenseFull;

        switch (_licenseKey) {
        case BeaconAboutLicense::GPL_V2:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "GPL v2", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "GNU General Public License Version 2", "@item license");
            break;
        case BeaconAboutLicense::LGPL_V2:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "LGPL v2", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "GNU Lesser General Public License Version 2", "@item license");
            break;
        case BeaconAboutLicense::BSDL:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "BSD License", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "BSD License", "@item license");
            break;
        case BeaconAboutLicense::Artistic:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "Artistic License", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "Artistic License", "@item license");
            break;
        case BeaconAboutLicense::QPL_V1_0:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "QPL v1.0", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "Q Public License", "@item license");
            break;
        case BeaconAboutLicense::GPL_V3:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "GPL v3", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "GNU General Public License Version 3", "@item license");
            break;
        case BeaconAboutLicense::LGPL_V3:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "LGPL v3", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "GNU Lesser General Public License Version 3", "@item license");
            break;
        case BeaconAboutLicense::LGPL_V2_1:
            licenseShort = QCoreApplication::translate("BeaconAboutLicense", "LGPL v2.1", "@item license (short name)");
            licenseFull = QCoreApplication::translate("BeaconAboutLicense", "GNU Lesser General Public License Version 2.1", "@item license");
            break;
        case BeaconAboutLicense::Custom:
        case BeaconAboutLicense::File:
            licenseShort = licenseFull = QCoreApplication::translate("BeaconAboutLicense", "Custom", "@item license");
            break;
        default:
            licenseShort = licenseFull = QCoreApplication::translate("BeaconAboutLicense", "Not specified", "@item license");
        }

        const QString result =
            (formatName == BeaconAboutLicense::ShortName) ? licenseShort :
            (formatName == BeaconAboutLicense::FullName) ?  licenseFull :
            QString();

        return result;
    }
private:
    LicenseKey _licenseKey;
    NameFormat _nameFormat;
    VersionRestriction _versionRestriction;
    QString _licenseText;
    QString _pathToLicenseTextFile;
    void setFilePath(const QString &filePath)
    {
        _pathToLicenseTextFile = filePath;
        _licenseText = BeaconFileIO::readFileContent(_pathToLicenseTextFile);
        if(_licenseText.isEmpty())_licenseKey = LicenseKey::Unknown;
        else _licenseKey = LicenseKey::File;
    }
    void setCustomText(const QString &text)
    {
        _licenseText = text;
        if(_licenseText.isEmpty())_licenseKey = LicenseKey::Unknown;
        else _licenseKey = LicenseKey::Custom;
    }
    void _updateText()
    {
        BeaconAboutLicenseContent content;
        QString target = QString();
        switch (_licenseKey) {
        case BeaconAboutLicense::GPL_V2:
            target = content.GPL();
            break;
        case BeaconAboutLicense::LGPL_V2:
            target = content.LGPL();
            break;
        case BeaconAboutLicense::BSDL:
            target = content.BSDL();
            break;
        case BeaconAboutLicense::Artistic:
            target = content.Artistic();
            break;
        case BeaconAboutLicense::QPL_V1_0:
            target = content.QPL();
            break;
        case BeaconAboutLicense::GPL_V3:
            target = content.GPL_V3();
            break;
        case BeaconAboutLicense::LGPL_V3:
            target = content.LGPL_V3();
            break;
        case BeaconAboutLicense::LGPL_V2_1:
            target = content.LGPL_V2_1();
            break;
        case BeaconAboutLicense::Custom:
        case BeaconAboutLicense::File:
            target = BeaconFileIO::readFileContent(_pathToLicenseTextFile);
            break;
        default:
            target = tr("No License was specified.");
            break;
        }
        _licenseText = target;
    }
};
class BeaconURLButton : public QPushButton{
    Q_OBJECT
public:
    BeaconURLButton(QString url,QIcon icon = QIcon(),QWidget *parent = nullptr)
        :QPushButton(icon,"",parent)
    {
        _url = url;
        if(_url.contains('@')){
            _url = "mailto:" + _url;
        }
        setToolTip(url);
    }
    QString URL(){return _url;}
private:
    QString _url;
};
class BeaconLibraryInfo : public QObject
{
    Q_OBJECT
public:
    BeaconLibraryInfo(const QString &name,
                      const QString &shortDescription,
                      const QString &version) {
        _name=name;
        _shortDescription=shortDescription;
        _version=version;
    }
    QString name(){return _name;}
    QString shortDescripton(){return _shortDescription;}
    QString version(){return _version;}
private:
    QString _name;
    QString _shortDescription;
    QString _version;
};
class BeaconAboutPersonWidget : public QWidget{
    Q_OBJECT
public:
    explicit BeaconAboutPersonWidget(const BeaconAboutPerson &person, QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        QLabel *nameLabel = new QLabel("<b>"+person.name()+"</b>",this);

        QLabel *taskLabel = new QLabel(person.task(),this);

        QHBoxLayout *buttonLayout = new QHBoxLayout(this);
        buttonLayout->setAlignment(Qt::AlignLeft);

        BeaconURLButton *emailButton = new BeaconURLButton(person.emailAddress(),
                                                           QIcon::fromTheme(QStringLiteral("internet-mail")),this);
        emailButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        BeaconURLButton *homepageButton = new BeaconURLButton(person.webAddress(),
                                                              QIcon::fromTheme(QStringLiteral("applications-internet")),this);
        homepageButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        BeaconURLButton *visitProfileButton = new BeaconURLButton(person.ocsUsername(),
                                                                  QIcon::fromTheme(QStringLiteral("get-hot-new-stuff")),this);
        visitProfileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        if(!person.emailAddress().isEmpty())buttonLayout->addWidget(emailButton);
        if(!person.webAddress().isNull())buttonLayout->addWidget(homepageButton);
        if(!person.ocsUsername().isNull())buttonLayout->addWidget(visitProfileButton);
        connect(emailButton,SIGNAL(clicked()),this,SLOT(linkActivated()));
        connect(homepageButton,SIGNAL(clicked()),this,SLOT(linkActivated()));
        connect(visitProfileButton,SIGNAL(clicked()),this,SLOT(linkActivated()));
        mainLayout->addWidget(nameLabel);
        mainLayout->addWidget(taskLabel);
        mainLayout->addLayout(buttonLayout);
        this->setLayout(mainLayout);
    }
    ~BeaconAboutPersonWidget(){}
private slots:
    void linkActivated(){
        BeaconURLButton *ori = qobject_cast<BeaconURLButton *>(sender());
        QString url = ori->URL();
        if (url.startsWith("http") || url.startsWith("mailto")) {
            QDesktopServices::openUrl(QUrl(url));
        }
        else {
            QMessageBox::information(this,tr("Information"),tr("His username is:%1").arg(url));
        }
    }
};

class BeaconAboutData{
public:
    static BeaconAboutData applicationData();
    static void setApplicationData(const BeaconAboutData &aboutData);
    BeaconAboutData(){
        QString text="Undefined";
        setComponentName(text);
        setDisplayName(text);
        setVersion(text.toUtf8());
        setShortDescription(text);
        setLicense(BeaconAboutLicense::Unknown,BeaconAboutLicense::VersionRestriction::OnlyThisVersion);
        setCopyrightStatement(text);
        setOtherText(text);
        setHomepage(text);
        setBugAddress(text.toUtf8());
        setBugCustomText(text);
    }
    BeaconAboutData(const QString &componentName,
               const QString &displayName,
               const QString &version,
               const QString &shortDescription,
               enum BeaconAboutLicense::LicenseKey licenseType = BeaconAboutLicense::LicenseKey::Unknown,
               const QString &copyrightStatement = QString(),
               const QString &otherText = QString(),
               const QString &homePageAddress = QString(),
               const QString &bugAddress = QStringLiteral("beacon1096@outlook.com"),
               const QString &bugCustomText = QString()
              )
    {
        setComponentName(componentName);
        setDisplayName(displayName);
        setVersion(version.toUtf8());
        setShortDescription(shortDescription);
        setLicense(licenseType,BeaconAboutLicense::VersionRestriction::OnlyThisVersion);
        setCopyrightStatement(copyrightStatement);
        setOtherText(otherText);
        setHomepage(homePageAddress);
        setBugAddress(bugAddress.toUtf8());
        setBugCustomText(bugCustomText);
    }
    BeaconAboutData(const BeaconAboutData &other){
        setComponentName(other._componentName);
        setDisplayName(other._displayName);
        setVersion(other._version);
        setShortDescription(other._shortDescription);
        for(auto it:other._licenseList){
            addLicense(it.key(),it._versionRestriction);
        }
        setCopyrightStatement(other._copyrightStatement);
        setOtherText(other._otherText);
        setHomepage(other._homepageAddress);
        setBugAddress(other._bugAddress.toUtf8());
        setBugCustomText(other._bugCustomText);
        for(auto it: other._authorList){
            _authorList.append(it);
        }
        for(auto it: other._creditList){
            _creditList.append(it);
        }
        for(auto it: other._licenseList){
            _licenseList.append(it);
        }
    }
    BeaconAboutData &operator=(const BeaconAboutData &other){
        setComponentName(other._componentName);
        setDisplayName(other._displayName);
        setVersion(other._version);
        setShortDescription(other._shortDescription);
        for(auto it:other._licenseList){
            addLicense(it.key(),it._versionRestriction);
        }
        setCopyrightStatement(other._copyrightStatement);
        setOtherText(other._otherText);
        setHomepage(other._homepageAddress);
        setBugAddress(other._bugAddress.toUtf8());
        setBugCustomText(other._bugCustomText);
        for(auto it: other._authorList){
            _authorList.append(it);
        }
        for(auto it: other._creditList){
            _creditList.append(it);
        }
        qDebug() << "copying data: " << other._licenseList.count() << " to go";
        for(auto it: other._licenseList){
            bool repeated = false;
            for(auto it2: _licenseList){
                if(it.key() == it2.key())
                {
                    repeated = true;
                    break;
                }
            }
            if(!repeated)_licenseList.append(it);
        }
        qDebug() << "this contains: " << this->licenses().count() << " licenses";
        return *this;
    }
    ~BeaconAboutData(){}
    QString displayName(){return _displayName;}
    QString componentName(){return _componentName;}
    QString version(){return _version;}
    QString shortDescription(){return _shortDescription;}
    QString copyrightStatement(){return _copyrightStatement;}
    QString otherText(){return _otherText;}
    QString homePageAddress(){return _homepageAddress;}
    QString bugAddress(){return _bugAddress;}
    QString bugCustomText(){return _bugCustomText;}
    QPixmap customImage(){return _customImage;}
    QList<BeaconAboutPerson> authors(){return _authorList;}
    QList<BeaconAboutPerson> credits(){return _creditList;}
    QList<BeaconAboutLicense> licenses(){return _licenseList;}
    QList<BeaconLibraryInfo> libraries(){return _libraryList;}
    void addAuthor(const QString &name,
                               const QString &task = QString(),
                               const QString &emailAddress = QString(),
                               const QString &webAddress = QString(),
                               const QString &ocsUsername = QString())
    {
         _authorList.append(BeaconAboutPerson(name,task,emailAddress,webAddress,ocsUsername));
    }
    void addCredit(const QString &name,
                   const QString &task = QString(),
                   const QString &emailAddress = QString(),
                   const QString &webAddress = QString(),
                   const QString &ocsUsername = QString())
    {
        _creditList.append(BeaconAboutPerson(name,task,emailAddress,webAddress,ocsUsername));
    }
    void addLibrary(const QString &name,
                    const QString &shortDescripton,
                    const QString &version)
    {
        _libraryList.append(BeaconLibraryInfo(name,shortDescripton,version));
    }
    void setComponentName(const QString &componentName){_componentName = componentName;}
    void setDisplayName(const QString &displayName){_displayName = displayName;}
    void setVersion(const QByteArray &version){_version = version;}
    void setShortDescription(const QString &shortDescription){_shortDescription = shortDescription;}
    void addLicense(BeaconAboutLicense::LicenseKey licenseKey,
                     BeaconAboutLicense::VersionRestriction versionRestriction
                     = BeaconAboutLicense::VersionRestriction::OnlyThisVersion)
    {
        if(_licenseList.count()==1 && _licenseList[0]._licenseKey == BeaconAboutLicense::LicenseKey::Unknown){
            _licenseList.clear();
        }
        _licenseList.append(BeaconAboutLicense(licenseKey,
                            BeaconAboutLicense::NameFormat::FullName,
                            versionRestriction));
    }
    void setLicense(BeaconAboutLicense::LicenseKey licenseKey,
                     BeaconAboutLicense::VersionRestriction versionRestriction
                     = BeaconAboutLicense::VersionRestriction::OnlyThisVersion)
    {
        _licenseList.clear();
        addLicense(licenseKey,versionRestriction);
    }
    void addLicenseText(const QString &license)
    {
        if(_licenseList.count()==1 && _licenseList[0]._licenseKey == BeaconAboutLicense::LicenseKey::Unknown){
            _licenseList.clear();
        }
        BeaconAboutLicense cuLicense;
        cuLicense.setCustomText(license);
        _licenseList.append(cuLicense);
    }
    void setLicenseText(const QString &license)
    {
        _licenseList.clear();
        addLicenseText(license);
    }
    void addLicenseTextFile(const QString &licenseFilePath)
    {
        if(_licenseList.count()==1 && _licenseList[0]._licenseKey == BeaconAboutLicense::LicenseKey::Unknown){
            _licenseList.clear();
        }
        BeaconAboutLicense cuLicense;
        cuLicense.setFilePath(licenseFilePath);
        _licenseList.append(cuLicense);
    }
    void setLicenseTextFile(const QString &licenseFilePath)
    {
        _licenseList.clear();
        addLicenseTextFile(licenseFilePath);
    }
    void setCopyrightStatement(const QString &copyrightStatement){_copyrightStatement = copyrightStatement;}
    void setOtherText(const QString &otherText){_otherText = otherText;}
    void setHomepage(const QString &homepage){_homepageAddress = homepage;}
    void setBugAddress(const QByteArray &bugAddress){_bugAddress = bugAddress;}
    void setBugCustomText(const QString &bugCustomText){_bugCustomText = bugCustomText;}
    void setCustomImage(const QPixmap &pixmap){_customImage = pixmap;}
    void setCustomImage(const QIcon &icon){_customImage = icon.pixmap(48,48);}
    void initBFPlugins(){
#ifdef BF_ABOUTDIALOG
        addLibrary(tr("AboutDialog",tr("KDE-like About Dialog"),BF_ABOUTDIALOGVERSION);
#endif
        #ifdef

        #endif
    }
private:
    QString _componentName;
    QString _displayName;
    QString _shortDescription;
    QString _copyrightStatement;
    QString _otherText;
    QString _homepageAddress;
    QString _bugAddress;
    QByteArray _version;
    QList<BeaconAboutPerson> _authorList;
    QList<BeaconAboutPerson> _creditList;
    QList<BeaconAboutPerson> _translatorList;
    QList<BeaconAboutLicense> _licenseList;
    QList<BeaconLibraryInfo> _libraryList;
    QString _bugCustomText;
    QPixmap _customImage;
};

class BeaconTitleWidget : public QWidget
{
    Q_OBJECT
public:
    enum ImageAlignment {
        ImageLeft, 
        ImageRight 
    };
    explicit BeaconTitleWidget(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        QFrame *titleFrame = new QFrame(this);
        /*titleFrame->setAutoFillBackground(true);
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Plain);
        titleFrame->setBackgroundRole(QPalette::Base);
        titleFrame->setContentsMargins(2,2,2,2);
        titleFrame->setLineWidth(1);
        titleFrame->setMidLineWidth(0);
        titleFrame->setFrameStyle(QFrame::Panel | QFrame::Plain);*/

        // default image / text part start
        headerLayout = new QGridLayout(titleFrame);
        headerLayout->setColumnStretch(0, 1);
        headerLayout->setMargin(6);
        headerLayout->setContentsMargins(0, 0, 0, 0);

        textLabel = new QLabel(titleFrame);
        textLabel->setVisible(false);
        textLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);

        imageLabel = new QLabel(titleFrame);
        imageLabel->setVisible(false);

        headerLayout->addWidget(textLabel, 0, 0);
        headerLayout->addWidget(imageLabel, 0, 1, 1, 2);

        commentLabel = new QLabel(titleFrame);
        commentLabel->setVisible(false);
        commentLabel->setOpenExternalLinks(true);
        commentLabel->setWordWrap(true);
        commentLabel->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::LinksAccessibleByMouse);
        headerLayout->addWidget(commentLabel, 1, 0);

        // default image / text part end

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(titleFrame);
        mainLayout->setMargin(2);
        setLayout(mainLayout);
    }
    ~BeaconTitleWidget() override{}
    QString text() const{return textLabel->text();}
    QString comment() const{return commentLabel->text();}
    const QPixmap *pixmap() const{return imageLabel->pixmap();}
    QFont setLevel(int targetLevel){
        level = targetLevel;

        textLabel->setStyleSheet(textStyleSheet());
        QFont font(textLabel->font());
        if(level<=4){
            font.setWeight(QFont::Light);
            font.setStyleName(QStringLiteral("Light"));
        } else {
            font.setWeight(QFont::Normal);
            font.setStyleName(QStringLiteral("Regular"));
        }
        return font;
    }
public slots:
    void setText(const QString &text, Qt::Alignment alignment = Qt::AlignLeft | Qt::AlignVCenter)
    {
        textLabel->setVisible(!text.isNull());

        if(!Qt::mightBeRichText(text)){
            QFont font = setLevel(level);
            textLabel->setFont(font);
        }
        textLabel->setText(text);
        textLabel->setAlignment(alignment);
        show();
    }
    void setComment(const QString &comment){
        commentLabel->setVisible(!comment.isNull());

        commentLabel->setText(comment);
        show();
    }
    void setPixmap(const QPixmap &pixmap, ImageAlignment alignment){
        imageLabel->setVisible(!pixmap.isNull());
        qDebug() << "update pixmap:isNull=" << pixmap.isNull();
        headerLayout->removeWidget(textLabel);
        headerLayout->removeWidget(commentLabel);
        headerLayout->removeWidget(imageLabel);

        if (alignment == ImageLeft) {
                headerLayout->addWidget(imageLabel, 0, 0, 2, 1);
                headerLayout->addWidget(textLabel, 0, 1);
                headerLayout->addWidget(commentLabel, 1, 1);
                headerLayout->setColumnStretch(0, 0);
                headerLayout->setColumnStretch(1, 1);
            } else {
                headerLayout->addWidget(textLabel, 0, 0);
                headerLayout->addWidget(commentLabel, 1, 0);
                headerLayout->addWidget(imageLabel, 0, 1, 2, 1);
                headerLayout->setColumnStretch(1, 0);
                headerLayout->setColumnStretch(0, 1);
            }
        imageLabel->setPixmap(pixmap);
    }
    void setPixmap(const QString &icon, ImageAlignment alignment){
        setPixmap(QIcon::fromTheme(icon),alignment);
    }
    void setPixmap(const QIcon &icon,ImageAlignment alignment){
        setPixmap(icon.pixmap(style()->pixelMetric(QStyle::PM_MessageBoxIconSize)),alignment);
    }
private:
    int level = 1;
    QString textStyleSheet() const
        {
            qreal factor;
            switch (level) {
            case 1:
                factor = 1.80;
                break;
            case 2:
                factor = 1.30;
                break;
            case 3:
                factor = 1.20;
                break;
            case 4:
                factor = 1.10;
                break;
            default:
                factor = 1;
            }
            const int fontSize = qRound(QApplication::font().pointSize() * factor);
            return QStringLiteral("QLabel { font-size: %1pt; color: %2 }").arg(QString::number(fontSize), palette().color(QPalette::WindowText).name());
        }
    QLabel *imageLabel = nullptr;
    QLabel *textLabel = nullptr;
    QLabel *commentLabel = nullptr;
    QGridLayout *headerLayout = nullptr;
};

class BeaconAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BeaconAboutDialog(const BeaconAboutData &ad,
                               QWidget *parent = nullptr)
    {
        aboutData = ad;
        //Layout
        this->setWindowTitle(tr("About %1").arg(aboutData.displayName()));
        this->setModal(false);

        QIcon windowIcon = qApp->windowIcon();
        setWindowIcon(windowIcon);

        mainLayout = new QVBoxLayout(this);

        //Title
        BeaconTitleWidget *titleWidget = new BeaconTitleWidget(this);
        titleWidget->setPixmap(windowIcon,BeaconTitleWidget::ImageLeft);
        qDebug() << "Checking for custom pixmap:isNull=" << aboutData.customImage().isNull();
        if(!aboutData.customImage().isNull()){
            titleWidget->setPixmap(aboutData.customImage(),BeaconTitleWidget::ImageLeft);
            qDebug() << "Custom Image set";
        }
        titleWidget->setText(tr("<html><font size=\"5\">%1</font><br />Version %2</html>").arg(aboutData.displayName()).arg(aboutData.version()));

        mainLayout->addWidget(titleWidget);
        //Tab Widget
        QTabWidget *tabWidget = new QTabWidget(this);
        tabWidget->setUsesScrollButtons(false);

        QLatin1Char enter = QLatin1Char('\n');
        //About
        QString aboutPageText = aboutData.shortDescription() + enter;
        if(!aboutData.otherText().isEmpty())
            aboutPageText += enter + aboutData.otherText() + enter;
        if(!aboutData.copyrightStatement().isEmpty())
            aboutPageText += enter + aboutData.copyrightStatement() + enter;
        if(!aboutData.homePageAddress().isEmpty())
            aboutPageText += enter + QStringLiteral("<a href=\"%1\">%1</a>").arg(aboutData.homePageAddress()) + enter;
        aboutPageText = aboutPageText.trimmed();
        QLabel *aboutLabel = new QLabel;
        aboutLabel->setWordWrap(true);
        aboutLabel->setOpenExternalLinks(true);
        aboutLabel->setText(aboutPageText.replace(QLatin1Char('\n'), QStringLiteral("<br />")));
        aboutLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);

        QVBoxLayout *aboutLayout = new QVBoxLayout;
        aboutLayout->addStretch();
        aboutLayout->addWidget(aboutLabel);

        int lim = aboutData.licenses().count();
        qDebug() << lim << "license(s) to go";
        for(int i=0;i<lim;i++){
            BeaconAboutLicense cuLicense = aboutData.licenses().at(i);
            QLabel *showLicenseLabel = new QLabel(this);
            showLicenseLabel->setText(QStringLiteral("<a href=\"%1\">%2</a>").
                                      arg(QString::number(i)).
                                      arg(cuLicense.name(BeaconAboutLicense::NameFormat::FullName)));
            showLicenseLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
            connect(showLicenseLabel, SIGNAL(linkActivated(QString)), this, SLOT(showLicense(QString)));

            aboutLayout->addWidget(showLicenseLabel);
        }

        aboutLayout->addStretch();

        QWidget *aboutWidget = new QWidget(this);
        aboutWidget->setLayout(aboutLayout);

        tabWidget->addTab(aboutWidget, tr("&About"));

        //Version
        QWidget *versionWidget = new QWidget(this);
        QVBoxLayout *versionLayout = new QVBoxLayout;
        QLabel *versionLabel = new QLabel(versionWidget);
        QLabel *librariesLabel = new QLabel(versionWidget);
        versionLabel->setText(QString("<ul><li>Beacon Frameworks %1</li><li>Qt %2 (built against %3)</li><li>The <em>%4</em> windowing system</li></ul>").
                              arg(QStringLiteral(BFABOUTDIALOGVERSION)).
                              arg(QString::fromLocal8Bit(qVersion())).
                              arg(QStringLiteral(QT_VERSION_STR)).
                              arg(QGuiApplication::platformName()));
        librariesLabel->setText("Libraries:");
        versionLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        librariesLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
        versionLayout->addWidget(versionLabel);
        versionLayout->addWidget(librariesLabel);
        versionLayout->addStretch();
        versionWidget->setLayout(versionLayout);
        tabWidget->addTab(versionWidget,tr("&Libraries"));

        //Authors
        const int authorCount = aboutData.authors().count();
        qDebug() << "authorCount:" << authorCount;
        //qDebug() << "authors:" << aboutData.authors().at(0).name();
        if(authorCount){
            QWidget *authorWidget = new QWidget(this);
            QVBoxLayout *authorLayout = new QVBoxLayout(authorWidget);
            authorLayout->setMargin(0);
            authorLayout->setAlignment(Qt::AlignTop);
            QLabel *bugLabel = new QLabel(authorWidget);
            if(!aboutData.bugCustomText().isEmpty()){
                QString link="mailto:beacon1096@outlook.com";
                if(!aboutData.bugAddress().isEmpty()){
                    link=aboutData.bugAddress();
                }
                QUrl bugUrl(link);
                if(bugUrl.scheme().isEmpty() && link.startsWith("mailto")){
                    bugUrl.setScheme(QStringLiteral("mailto"));
                }
                bugLabel->setText(tr("Please report bugs to <a href=\"%1\">%2</a>.\n").
                                  arg(bugUrl.toString()).
                                  arg(link));
            } else {
                bugLabel->setText(aboutData.bugCustomText());
            }
            authorLayout->addWidget(bugLabel);

            for(auto it: aboutData.authors()){
                BeaconAboutPersonWidget *newAuthor = new BeaconAboutPersonWidget(it,this);
                authorLayout->addWidget(newAuthor);
            }
            authorWidget->setLayout(authorLayout);
            tabWidget->addTab(authorWidget,"A&uthors");
        }

        mainLayout->addWidget(tabWidget);
        qDebug() << "Setting up";
        this->setLayout(mainLayout);
    }
    ~BeaconAboutDialog()
    {

    }
private:
    //Data
    BeaconAboutData aboutData;
    //Layouts
    QVBoxLayout *mainLayout = nullptr;
private slots:
    void showLicense(const QString &number){
        QDialog *dialog = new QDialog(this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        QVBoxLayout *layout = new QVBoxLayout;
        dialog->setLayout(layout);

        dialog->setWindowTitle(tr("License Agreement"));

        const QFont font = QFontDatabase::systemFont(QFontDatabase::FixedFont);
        QFontMetrics metrics(font);

        const QString licenseText = aboutData.licenses().at(number.toInt()).text();
        QTextBrowser *licenseBrowser = new QTextBrowser(dialog);
        licenseBrowser->setFont(font);
        licenseBrowser->setLineWrapMode(QTextEdit::NoWrap);
        licenseBrowser->setText(licenseText);
        layout->addWidget(licenseBrowser);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(dialog);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        connect(buttonBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);
        layout->addWidget(buttonBox);

        // try to set up the dialog such that the full width of the
        // document is visible without horizontal scroll-bars being required
        const int marginHint = dialog->style()->pixelMetric(QStyle::PM_DefaultChildMargin);
        const qreal idealWidth = licenseBrowser->document()->idealWidth() + (2 * marginHint)
                                 + licenseBrowser->verticalScrollBar()->width() * 2;

        // try to allow enough height for a reasonable number of lines to be shown
        const int idealHeight = metrics.height() * 30;

        dialog->resize(dialog->sizeHint().expandedTo(QSize(qRound(idealWidth), idealHeight)));
        dialog->adjustSize();
        dialog->show();
    }

};



#endif // BF_ABOUTDIALOG
