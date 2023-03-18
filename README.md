# EXPORT MEDIAPIPE TO DLL
尚未上生产，注意安全

**make sure you can compile mediapipe successfully**

**make sure you can compile mediapipe successfully**

**make sure you can compile mediapipe successfully**

下面描述这个项目的构建过程，方便其他 bazel 项目也参考类似方式去搞。
```shell
git submodule init && git submodule update
```
1. change lib/mediapipe/WORKSPACE openCV path
2. copy lib/media_wrapper/WORKSPACE to ./WORKSPACE
3. replace `workspace(name = "mediapipe")` to `workspace(name = "project_name")` in ./WORKSPACE
4. add the following in ./WORKSPACE:
```
local_repository(
    name = "mediapipe",
    path = "lib/mediapipe"
)
```
5. replace all `@//third_party` to `@mediapipe//third_party` in ./WORKSPACE 
6. change yarn_install to in ./WORKSPACE

```
yarn_install(
    name = "npm",
    package_json = "@mediapipe//:package.json",
    yarn_lock = "@mediapipe//:yarn.lock",
)

```
5. copy file in `lib\mediapipe\.bazelrc` to `.\.bazelrc` 


# Run
```
#PYTHON_BIN_PATH should change.
bazel run  --experimental_repo_remote_exec --define MEDIAPIPE_DISABLE_GPU=1 --action_env PYTHON_BIN_PATH="C:/Users/Administrator/AppData/Local/Microsoft/WindowsApps/python.exe" src:hello_world

```


中文可参考 https://blog.csdn.net/HW140701/article/details/119546019 来编译 MEDIAPIPE 
