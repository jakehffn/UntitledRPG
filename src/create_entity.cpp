#include "create_entity.h"

void create_entity::VSCodeBackground(entt::registry& registry) {

    const auto background = registry.create();
    registry.emplace<Sprite>(background, "./src/assets/sprites/ScreenShot (76).png");
    registry.emplace<Model>(background, glm::mat4(10));
    registry.emplace<Spacial>(background, glm::vec3(0, 0, -.5), glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
}

void create_entity::Map1Background(entt::registry& registry) {

    const auto background = registry.create();
    registry.emplace<Sprite>(background, "./src/assets/sprites/Maps/UntitledRPG.png");
    registry.emplace<Model>(background, glm::mat4(10));
    registry.emplace<Spacial>(background, glm::vec3(0, 0, -.5), glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
}

void create_entity::Player(entt::registry& registry, glm::vec3 pos) {

    const auto player = registry.create();
    registry.emplace<Model>(player, glm::mat4(10));
    registry.emplace<Spacial>(player, pos, glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
    registry.emplace<Velocity>(player);
    registry.emplace<Collision>(player, glm::vec2(16, 24));
    registry.emplace<Input>(player, 200.0f);
    registry.emplace<CameraController>(player, 650.0f);

    registry.emplace<Sprite>(player, "./src/assets/sprites/Kid/Kid_IdleDown.png");
    registry.emplace<Animation>(player, std::vector<int>{0,0,0});//solve necessity for animations longer than 1 frame        

    Sprite idleUpSprite("./src/assets/sprites/Kid/Kid_IdleUp.png");
    Sprite moveUpSprite("./src/assets/sprites/Kid/Kid_MoveUp.png", 4);
    Sprite idleDownSprite("./src/assets/sprites/Kid/Kid_IdleDown.png");
    Sprite moveDownSprite("./src/assets/sprites/Kid/Kid_MoveDown.png", 4);
    Sprite idleLeftSprite("./src/assets/sprites/Kid/Kid_IdleLeft.png");
    Sprite moveLeftSprite("./src/assets/sprites/Kid/Kid_MoveLeft.png", 4);
    Sprite idleRightSprite("./src/assets/sprites/Kid/Kid_IdleRight.png");
    Sprite moveRightSprite("./src/assets/sprites/Kid/Kid_MoveRight.png", 4);

    Animation moveAnim{std::vector<int>{0,1,2,3}}; 
    Animation idleAnim{std::vector<int>{0,0}};

    std::unordered_map<SpriteStatePair, std::tuple<Sprite, Animation>, pair_hash> stateMap{
        {std::make_pair(entity_c::IDLE, entity_c::UP), std::tuple<Sprite, Animation>(idleUpSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::DOWN), std::tuple<Sprite, Animation>(idleDownSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::LEFT), std::tuple<Sprite, Animation>(idleLeftSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::RIGHT), std::tuple<Sprite, Animation>(idleRightSprite, idleAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::UP), std::tuple<Sprite, Animation>(moveUpSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::DOWN), std::tuple<Sprite, Animation>(moveDownSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::LEFT), std::tuple<Sprite, Animation>(moveLeftSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::RIGHT), std::tuple<Sprite, Animation>(moveRightSprite, moveAnim)}

    };

    registry.emplace<SpriteState>(player, stateMap);
}

void create_entity::BoxHead(entt::registry& registry, glm::vec3 pos) {

    const auto boxHead = registry.create();
    registry.emplace<Model>(boxHead, glm::mat4(10));
    registry.emplace<Spacial>(boxHead, pos, glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
    registry.emplace<Input>(boxHead, 675.0f);
    registry.emplace<CameraController>(boxHead, 675.0f);

    registry.emplace<Sprite>(boxHead, "./src/assets/sprites/BoxHead/BoxHead_IdleDown.png");
    registry.emplace<Animation>(boxHead, std::vector<int>{0,0,0});//solve necessity for animations longer than 1 frame        

    Sprite idleUpSprite("./src/assets/sprites/BoxHead/BoxHead_IdleUp.png");
    Sprite moveUpSprite("./src/assets/sprites/BoxHead/BoxHead_MoveUp.png", 8);
    Sprite idleDownSprite("./src/assets/sprites/BoxHead/BoxHead_IdleDown.png");
    Sprite moveDownSprite("./src/assets/sprites/BoxHead/BoxHead_MoveDown.png", 8);
    Sprite idleLeftSprite("./src/assets/sprites/BoxHead/BoxHead_IdleLeft.png");
    Sprite moveLeftSprite("./src/assets/sprites/BoxHead/BoxHead_MoveLeft.png", 8);
    Sprite idleRightSprite("./src/assets/sprites/BoxHead/BoxHead_IdleRight.png");
    Sprite moveRightSprite("./src/assets/sprites/BoxHead/BoxHead_MoveRight.png", 8);

    Animation moveUpAnim{std::vector<int>{0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0}};
    Animation moveAnim{std::vector<int>{0,1,2,3,4,5,6,7}}; 
    Animation idleAnim{std::vector<int>{0,0}};

    std::unordered_map<SpriteStatePair, std::tuple<Sprite, Animation>, pair_hash> stateMap{
        {std::make_pair(entity_c::IDLE, entity_c::UP), std::tuple<Sprite, Animation>(idleUpSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::DOWN), std::tuple<Sprite, Animation>(idleDownSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::LEFT), std::tuple<Sprite, Animation>(idleLeftSprite, idleAnim)},
        {std::make_pair(entity_c::IDLE, entity_c::RIGHT), std::tuple<Sprite, Animation>(idleRightSprite, idleAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::UP), std::tuple<Sprite, Animation>(moveUpSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::DOWN), std::tuple<Sprite, Animation>(moveDownSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::LEFT), std::tuple<Sprite, Animation>(moveLeftSprite, moveAnim)},
        {std::make_pair(entity_c::MOVING, entity_c::RIGHT), std::tuple<Sprite, Animation>(moveRightSprite, moveAnim)}

    };

    registry.emplace<SpriteState>(boxHead, stateMap);
}

void create_entity::Bag(entt::registry& registry, glm::vec3 pos) {

    const auto bag = registry.create();
    registry.emplace<Sprite>(bag, "./src/assets/sprites/Bag.png", 5);
    registry.emplace<Model>(bag, glm::mat4(10));
    registry.emplace<Spacial>(bag, pos, glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
    registry.emplace<Animation>(bag, std::vector<int>{0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0});        
}

void create_entity::CollisionBox(entt::registry& registry, glm::vec2 pos, glm::vec2 dim) {

    const auto collision = registry.create();

    registry.emplace<Spacial>(collision, glm::vec3(pos.x, pos.y, 0), glm::vec3(0, 0, 0), 
        glm::vec3(1, 1, 1));
    registry.emplace<Collision>(collision, dim);
}