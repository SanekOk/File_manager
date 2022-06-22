#include "File_Manager.h"

File_Manager::File_Manager() = default;


File_Manager::File_Manager(const string& val)
{
    name=val;
    Way = "C:\\";
}

File_Manager::~File_Manager(){}


string File_Manager::getName() const
{
    return name;
}

void File_Manager::setName(const string& val)
{
    name = val;
}


string File_Manager::getWay() const
{
    return Way;
}

void File_Manager::setWay(const string& val)
{
    Way =val;
}

void File_Manager::Content() const
{
    for (const auto& entry : directory_iterator(Way))
    {
        cout << entry.path().filename() << endl;
    }
}

void File_Manager::Create() const
{
    int var = 0;
    cout << "Create catalog-> 1; Create file-> 2 ";
    cin >> var;
    switch (var)
    {
    case 1:
        if (_mkdir(name.c_str()) == 0)
        {
            cout << "Catalog was created successfully" << endl;
        }
        else
        {
            cout << "Catalog not created" << endl;
        }
        break;
    case 2:
        if (_creat(name.c_str(), S_IWRITE) != 0)
        {
            cout << "File was created successfully" << endl;
        }
        else
        {
            cout << "File not created" << endl;
        }
        break;
    default:
        cout << "This is not creating" << endl;
        break;
    }
}

void File_Manager::Delete() const
{

    int var = 0;
    cout << "Delete catalog-> 1; Delete file-> 2 ";
    cin >> var;
    switch (var)
    {
    case 1:
        if (_rmdir(name.c_str()) == 0)
        {
            cout << "Directory deleted successfully" << endl;
        }
        else
        {
            cout << "Catalog not deleted" << endl;
        }
        break;
    case 2:
        if (remove(name) != 0)
        {
            cout << "File was deleted successfully" << endl;
        }
        else
        {
            cout << "File not deleted" << endl;
        }
        break;
    default:
        cout << "This is not deleted" << endl;
        break;
    }
}

void File_Manager::Rename() const
{
    string okk = Way;
    string buf;
    cout << "Введите новое имя: ";
    getline(cin, buf);
    while (okk.back() != '\\')
    {
        okk.pop_back();
    }
    auto size= okk.size();
    okk.insert(size,buf);
     rename(Way, okk);
}

void File_Manager::Copy_File(string val, string next)
{
     copy(val, next);
}

void File_Manager::Size() const
{
    auto a = file_size(Way);
    cout << "Size: " << a << " Bait" << endl;
}

bool File_Manager::t_if(string val)
{
    if (val.size() > 3)
    {
        for (auto i = 0; i < 3; ++i)
        {
            val.pop_back();
        }
    }
    if (val.back() == '.')
        return true;
    else
        return false;
}

bool File_Manager::t_compare(string jnior)
{
    string buf;
    string next;
    if (t_if(jnior) == 0)
    {
        while (jnior.back() != '\\')
        {
            next = jnior.back();
            buf.insert(0, next);
            jnior.pop_back();
        }
        return strcmp(buf.c_str(), name.c_str());// Совпало -> 0

        cout << buf << endl;
    }
    else
    {
        for (auto i = 0; i < 4; ++i)
        {
            jnior.pop_back();
        }
        while (jnior.back() != '\\')
        {
            next = jnior.back();
            buf.insert(0, next);
            jnior.pop_back();
        }
        return strcmp(buf.c_str(), name.c_str());// Совпало -> 0
    }
}

string File_Manager::Search()
{
    if (t_compare(Way) == 0)
    {
        return Way;
    }
    else if (t_compare(Way) != 0)
    {
        for (const auto& entry : directory_iterator(Way))
        {
            string mko = entry.path().string();
            Way = mko;
            if (Way != "C:\\Users\\User\\AppData\\Roaming\\Microsoft\\Windows\\Recent")
            {
                if (t_if(Way) == 0)
                {
                    int s = _chdir(mko.c_str());
                    if (s == 0)
                    {
                        Search();
                    }
                }
            }
            if (t_compare(Way) == 0)
            {
                return Way;
                break;
            }
        }
        return Way;
    }
}

