#include <iostream>
#include <string>
#include <memory>

class ColorCamera {
public:
    virtual void captureColorImage() = 0;
};

class BlackAndWhiteCamera {
public:
    void captureBWImage() {
        std::cout << "Capturing black and white image.\n";
    }
};

class BWToColorCameraAdapter : public ColorCamera {
private:
    BlackAndWhiteCamera bwCamera;

public:
    BWToColorCameraAdapter(const BlackAndWhiteCamera& legacyCamera) : bwCamera(legacyCamera) {}

    void captureColorImage() override {
        std::cout << "Converting black and white image to color image.\n";
        std::cout << "Applying color to the image.\n";
        bwCamera.captureBWImage();
        std::cout << "Adapting black and white camera to capture color images.\n";
    }
};

class ModernPhotographySystem {
public:
    void takePhoto(ColorCamera& colorCamera) {
        std::cout << "Modern Photography System: ";
        colorCamera.captureColorImage();
    }
};

int main() {
    auto bwCamera = std::make_shared<BlackAndWhiteCamera>();
    auto colorAdapter = std::make_shared<BWToColorCameraAdapter>(*bwCamera);
    auto photographySystem = std::make_shared<ModernPhotographySystem>();

    photographySystem->takePhoto(*colorAdapter);
}
