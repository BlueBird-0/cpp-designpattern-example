#include <cstring>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class Document {
  public:
    virtual bool Open(const char *pFileName) = 0;
};

class HwpDocumnet : public Document {
  public:
    bool Open(const char *pFileName) override {
        ifstream ifs(pFileName);
        if (!ifs)
            return false;
        return true;
    }
};

class MsWordDocument : public Document {
  public:
    bool Open(const char *pFileName) override {
        ifstream ifs(pFileName);
        if (!ifs)
            return false;
        return true;
    }
};

class AnotherDocument : public Document {
  public:
    bool Open(const char *pFileName) override {
        ifstream ifs(pFileName);
        if (!ifs)
            return false;
        return true;
    }
};

class Application {
  public:
    virtual Document *CreateDocument(int docType) {
        switch (docType) {
        case HWP_DOCUMENT:
            return new HwpDocumnet;
        case MSWORD_DOCUMENT:
            return new MsWordDocument;
        case ANOTHER_DOCUMENT:
            return new AnotherDocument;
        }
        return 0;
    };

    void NewDocument(const char *pFileName) {
        Document *pDoc = CreateDocument(GetDocType(pFileName));
        docs_[pFileName] = pDoc;
        pDoc->Open(pFileName);
    }

  protected:
    enum {
        HWP_DOCUMENT = 0,
        MSWORD_DOCUMENT = 1,
        ANOTHER_DOCUMENT = 2,
        UNDEF_DOCUMENT = 3,
    };

    int GetDocType(const char *pFileName) {
        const char *pExt = strrchr(pFileName, '.');
        if (strcmp(pExt, ".hwp") == 0) {
            return HWP_DOCUMENT;
        } else if (strcmp(pExt, ".doc") == 0) {
            return MSWORD_DOCUMENT;
        } else {
            return UNDEF_DOCUMENT;
        }
    }

  private:
    map<string, Document *> docs_;
};

class HwpApplication : public Application {
  public:
    Document *CreateDocument(int) override { return new HwpDocumnet(); }
};

class MsWordApplication : public Application {
  public:
    Document *CreateDocument(int) override { return new MsWordDocument(); }
};

class AnotherApplication : public Application {
  public:
    Document *CreateDocument(int docType) override {
        if (docType == ANOTHER_DOCUMENT)
            return new AnotherDocument();
        else
            return Application::CreateDocument(docType);
    }
};

// using template
template <class T> class ConcreteApplication : public Application {
  public:
    Document *CreateDocument(int) override { return new T(); }
};

int main() {
    HwpApplication hwpApp;
    hwpApp.NewDocument("input.hwp");

    AnotherApplication anotherApp;
    anotherApp.NewDocument("input.doc");

    ConcreteApplication<MsWordDocument> app;
    app.NewDocument("input.doc");

    cout << "Hello Factory Method Pattern" << endl;
}