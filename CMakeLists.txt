cmake_minimum_required(VERSION 3.21)
project(HappyAccident VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# JUCE는 워크플로우에서 ./juce 로 clone 됨
add_subdirectory(juce)

set(JUCE_COMPANY_NAME "HappyApps")
set(JUCE_BUNDLE_ID    "com.happyapps.happyaccident")

juce_add_plugin(HappyAccident
    COMPANY_NAME        ${JUCE_COMPANY_NAME}
    BUNDLE_ID           ${JUCE_BUNDLE_ID}
    IS_SYNTH            FALSE
    NEEDS_MIDI_INPUT    FALSE
    NEEDS_MIDI_OUTPUT   FALSE
    IS_MIDI_EFFECT      FALSE
    FORMATS             AU VST3
    PRODUCT_NAME        "HappyAccident"
)

target_sources(HappyAccident PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
)

target_compile_definitions(HappyAccident PRIVATE
    JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(HappyAccident PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
    juce::juce_gui_extra
    juce::juce_gui_basics
    juce::juce_audio_basics
    juce::juce_core
)
