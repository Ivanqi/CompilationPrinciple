#include <iostream>

#include "ReportTemplate.h"
#include "TabularData.h"
#include "PlayReport.h"

using namespace std;

int main(int argc, const char* argv[]) {

    cout << "Play Report!" << endl;

    PlayReport *report = new PlayReport();

    // 打印报表1
    string reportString = report->renderReport(ReportTemplate::sampleReport1(), TabularData::sampleData());
    cout << reportString << endl;

    // 打印报表2
    reportString = report->renderReport(ReportTemplate::sampleReport2(), TabularData::sampleData()); 
    cout << reportString << endl;

    return 0;
}