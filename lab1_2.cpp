#include <iostream>
#include <string>
using namespace std;

class Url {
    string url;
    public:
        Url(string u) {
            url = u;
        }
};

class Account {
    string acc;
    public:
        Account(string a) {
            acc = a;
        }
};

class Image {
    string img_name;
    int width = 720, height = 360;
    // colors
    public:
        Image(string ch, int w, int h) {
            img_name = ch;
            width = w;
            height = h;
        }
        void set_img_name(string ch) {
            img_name = ch;
        }
        string get_img_name() {
            return img_name;
        }
        void set_img_size(int w, int h) {
            width = w;
            height = h;
        }
        string get_img_size () {
            return "Width: " + to_string(width) + " Height: " + to_string(height);
        }
};

// изменение размеров изображения
class ImgResizer {
    virtual void Resize(Image&, int, int) = 0;
};

class ImgOptResize: ImgResizer {
    void Reize(Image& img, int width, int height) {
        // processing
    }
};

// изменить цвета на изображении
class ImgColorsInverter {
    virtual void InvertColors(Image&) = 0;
};

class ImgNegFilt: ImgColorsInverter {
    public:
        void InvertColors(Image& img) {
            // processing
        }
};

class ImgSavior {
    virtual void Save(Image&) = 0;
};

// сохранение изображения в файловой системе
class ImgSavePDF: ImgSavior {
    public:
        void Save(Image& img) {
            // saving
        }
};

class ImgDuplicatesCleaner {
    virtual int DeleteDuplicates(string) = 0;
    // virtual int DeleteDuplicates(string PATH?) = 0;
};

// удалить из файловой системы все дублирующиеся изображения и вернуть количество удаленных
class ImgDuplicatesCleanerByName: ImgDuplicatesCleaner {
    public:
        int DeleteDuplicates() {
            int del = 0;
            // delete files with same names
            return del;
        }
};

// запрос к базе данных для сохранения ссылки на это изображение для пользователя
class ImgAsAccountPictureSetter {
    virtual Image SetImageAsAccountPicture(Image&, Account) = 0;
};

class ImgAsAccountPictureSetter_Win: ImgAsAccountPictureSetter {
    public:
        Image SetImageAsAccountPicture(Image& img, Account acc) {
            // processing
            return img;
        }
};

// загрузка битового массива с изображением с помощью HTTP запроса
class ImgDownloader {
    virtual byte* Download(Url imageUrl) = 0;
};

class ImgDownloader_smth: ImgDownloader {
    public:
        byte* Download(Url imageUrl) {
            // processing
            return 0;
        }
};

int main() {
    Image s("Starship", 1920, 1080);
    cout << s.get_img_name() << " " << s.get_img_size() << "\n";
    s.set_img_size(152, 12345);
    cout << s.get_img_name() << " " << s.get_img_size() << "\n";

    return 0;
}